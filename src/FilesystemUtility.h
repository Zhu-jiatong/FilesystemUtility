#if !defined(_FilesystemUtility_h)
#define _FilesystemUtility_h

#include <FS.h>

namespace FSUtil
{
	void recursiveDelete(FS &fs, File &root);
	bool isChildOf(const String &parent, const String &child);
	String parentPath(const String &path);

	class DirectoryIterator;
} // namespace FSUt

#include "DirectoryIterator.h"

#endif // _FilesystemUtility_h
