#include "FilesystemUtility.h"
#include <stack>

void FSUtil::recursiveDelete(FS &fs, File &root)
{
	while (File entry = root.openNextFile())
	{
		if (entry.isDirectory())
			recursiveDelete(fs, entry);
		else
		{
			String path = entry.path();
			entry.close();
			if (!fs.remove(path))
				throw std::runtime_error(("Failed to remove file: " + path).c_str());
		}
	}
	String path = root.path();
	root.close();
	if (!fs.rmdir(path))
		throw std::runtime_error(("Failed to remove directory: " + path).c_str());
}

bool FSUtil::isChildOf(const String &parent, const String &child)
{
	if (parent.length() >= child.length())
		return false;
	if (child.indexOf(parent) != 0)
		return false;
	if (child.charAt(parent.length()) != '/')
		return false;
	return true;
}

String FSUtil::parentPath(const String &path)
{
	int lastSlash = path.lastIndexOf('/');

	if (lastSlash == 0)
		return "/";

	if (lastSlash == path.length() - 1)
		return parentPath(path.substring(0, lastSlash));

	if (lastSlash == -1)
		return "";

	return path.substring(0, lastSlash);
}