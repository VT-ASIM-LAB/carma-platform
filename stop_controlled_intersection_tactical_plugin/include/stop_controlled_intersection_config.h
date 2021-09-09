#pragma once

/*
 * Copyright (C) 2021 LEIDOS.
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may not
 * use this file except in compliance with the License. You may obtain a copy of
 * the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations under
 * the License.
 */

#include <iostream>

/**
 * \brief Stuct containing the algorithm configuration values for the StopControlledIntersectionTacticalPlugin
 */
struct StopControlledIntersectionTacticalPluginConfig
{
    double trajectory_time_length = 6.0;     // Trajectory length in seconds
    double curve_resample_step_size = 1.0;   // Curve re-sampling step size in m
    bool publish_debug = false;
    double centerline_sampling_spacing = 1.0;  // The gap in meters between points sampled from the lanelet centerlines for planning trajectory positions
    int curvature_moving_average_window_size = 9;  // Size of the window used in the moving average filter to smooth the curvature profile
                                           // computed curvature and output speeds
    double lateral_accel_limit = 2.5;        // Maximum allowable lateral acceleration m/s^2   
    int speed_moving_average_window_size = 5;      // Size of the window used in the moving average filter to smooth both the speed profile                                        

    friend std::ostream& operator<<(std::ostream& output, const StopControlledIntersectionTacticalPluginConfig& c)
    {
        output <<"StopControlledIntersectionTacticalPluginConfig { " <<std::endl
                << "trajectory_time_length: " << c.trajectory_time_length << std::endl
                << "curve_resample_step_size: " << c.curve_resample_step_size << std::endl
                << "cernterline_sampling_spacing: " << c.centerline_sampling_spacing << std::endl
                << "curvature_moving_average_window_size: " << c.curvature_moving_average_window_size << std::endl
                << "lateral_accel_limit: " << c.lateral_accel_limit << std::endl
                 << "speed_moving_average_window_size: " << c.speed_moving_average_window_size << std::endl
                << "}" << std::endl;
        return output;
    }
};