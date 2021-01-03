// Copyright 2019-2020 Raphael Hungria
#include <cstdint>

#include "repch.h"

#include "RaphEn/profiler//profiler_timer.h"
#include "RaphEn/profiler/profiler.h"

namespace raphen::debug {
ProfilerTimer::ProfilerTimer(const char* name) :
    m_name(name),
    m_stopped(false) {
    m_start_timepoint = std::chrono::high_resolution_clock::now();
}

ProfilerTimer::~ProfilerTimer() {
    if (!m_stopped)
        Stop();
}

void ProfilerTimer::Stop() {
    auto endpoint = std::chrono::high_resolution_clock::now();

    int64_t start = std::chrono::time_point_cast<std::chrono::microseconds>
        (m_start_timepoint).time_since_epoch().count();
    int64_t end = std::chrono::time_point_cast<std::chrono::microseconds>
        (endpoint).time_since_epoch().count();

    uint32_t thread_id = (uint32_t)std::hash<std::thread::id>{}
        (std::this_thread::get_id());
    Profiler::Get().WriteProfile({ m_name, start, end, thread_id });

    m_stopped = true;
}
}  // namespace raphen::debug