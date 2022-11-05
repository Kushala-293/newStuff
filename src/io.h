#pragma once

#include <optional>
#include <vector>

#include "profilepoint.h"

namespace squiggles {
	/**
	 * Writes the path data to a CSV file.
	 *
	 * @param out The output stream to write the CSV data to. This is usually a
	 * file.
	 * @param path The path to serialized
	 *
	 * @return 0 if the path was serialized succesfully or -1 if an error occurred.
	 */
	int serialize_path(std::ostream& out, std::vector<ProfilePoint> path);

	int serialize_path_array_format(std::ostream& out, std::vector<ProfilePoint> path, std::string preType);

	int serialize_path_array_formatDim(std::ostream& out, std::vector<ProfilePoint> path, std::string preType);

	int serialize_path_header2D(std::ostream& out, std::vector<ProfilePoint> path, std::string preType);

	int serialize_path_headerCustom(std::ostream& out, std::vector<ProfilePoint> path, std::string preType);




	/**
	 * Converts CSV data into a path.
	 *
	 * @param in The input stream containing the CSV data. This is usually a file.
	 *
	 * @return The path specified by the CSV data or std::nullopt if de-serializing
	 *         the path was unsuccessful.
	 */
	std::optional<std::vector<ProfilePoint>> deserialize_path(std::istream& in);

	/**
	 * Converts CSV data from the Pathfinder library's format to a Squiggles path.
	 *
	 * NOTE: this code translates data from Jaci Brunning's Pathfinder library.
	 * The source for that library can be found at:
	 * https://github.com/JaciBrunning/Pathfinder/
	 *
	 * @param left The input stream containing the left wheels' CSV data. This is
	 *             usually a file.
	 * @param right The input stream containing the right wheels' CSV data. This is
	 *             usually a file.
	 *
	 * @return The path specified by the CSV data or std::nullopt if de-serializing
	 *         the path was unsuccessful.
	 */
	std::optional<std::vector<ProfilePoint>>
		deserialize_pathfinder_path(std::istream& left, std::istream& right);
} // namespace squiggles