#pragma once

/*
 * Copyright (C) 2015 Alex Smith
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */


#include <string>

enum class LogLevel {
    Trace,
    Debug,
    Unimplemented,
    Info,
    Warning,
    Error,
};

class Logger {
public:
    Logger();
    void log(LogLevel level, const char* fmt, ...);
    void set_level(LogLevel level);
    void enable_tracing();

private:
    bool should_log(LogLevel level) const;
    const char* level_color(LogLevel level) const;

    LogLevel current_level = LogLevel::Debug;
    bool enabled = true;
    bool tracing_enabled = false;
};

extern Logger global_logger;
extern const char* COLOR_TRACE;
extern const char* COLOR_DEBUG;
extern const char* COLOR_UNIMPLEMENTED;
extern const char* COLOR_INFO;
extern const char* COLOR_WARNING;
extern const char* COLOR_ERROR;
extern const char* COLOR_RESET;

#define log_trace(fmt, ...) \
    global_logger.log(LogLevel::Trace, fmt, ##__VA_ARGS_);

#define log_debug(fmt, ...) \
    global_logger.log(LogLevel::Debug, fmt, ##__VA_ARGS_);

#define log_unimplemented(fmt, ...)\
    global_logger.log(LogLevel::Unimplemented, fmt, ##__VA_ARGS_);

#define log_info(fmt, ...)\
    global_logger.log(LogLevel::Info, fmt, ##__VA_ARGS_);

#define log_warning(fmt, ...)\
    global_logger.log(LogLevel::Warning, fmt, ##__VA_ARGS_);

#define log_error(fmt, ...)\
    global_logger.log(LogLevel::Error, fmt, ##__VA_ARGS_);

extern void log_set_level(LogLevel level);