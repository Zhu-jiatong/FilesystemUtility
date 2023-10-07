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
