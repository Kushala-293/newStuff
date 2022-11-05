#pragma once

#include <cmath>
#include <string>

#include "utils.h"

namespace squiggles {
    class Pose {
    public:
        /**
         * Specifies a point and heading in 2D space.
         *
         * @param ix The x position of the point in meters.
         * @param iy The y position of the point in meters.
         * @param iyaw The heading at the point in radians.
         */
        Pose(double ix, double iy, double iyaw) : x(ix), y(iy), yaw(iyaw) {}

        Pose() = default;

        /**
         * Calculates the Euclidean distance between this pose and another.
         *
         * @param other The point from which the distance will be calculated.
         *
         * @return The distance between this pose and Other.
         */
        double dist(const Pose& other) const {
            return std::sqrt((x - other.x) * (x - other.x) +
                (y - other.y) * (y - other.y));
        }

        /**
         * Serializes the Pose data for debugging.
         *
         * @return The Pose data.
         */
        std::string to_string() const {
            return "Pose: {x: " + std::to_string(x) + ", y: " + std::to_string(y) +
                ", yaw: " + std::to_string(yaw) + "}";
        }

        std::string to_csv() const {
            return std::to_string(x) + "," + std::to_string(y) + "," +
                std::to_string(yaw);
        }

        bool operator==(const Pose& other) const {
            return nearly_equal(x, other.x) && nearly_equal(y, other.y) &&
                nearly_equal(yaw, other.yaw);
        }

        double x;
        double y;
        double yaw;
    };
} // namespace squiggles