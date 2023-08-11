#pragma once
#include <libnotify/notify.h>
#include <dpp/dpp.h>
#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <X11/Xutil.h>
#include <X11/XKBlib.h>
#include <thread>
#include <chrono>
#include <stdexcept>
#include <memory>
#include <cstdio>
#include <unistd.h>
#include <functional>
#include "../dotenv.h"
#include <fstream>
#include <array>
#include "../config_var/main.cpp"

std::string exec_parsed(const std::string);
void show_encrypted(NotifyNotification*& notification);
void block_input();