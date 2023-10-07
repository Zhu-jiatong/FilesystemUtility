#if !defined(_FilesystemUtility_h)
#define _FilesystemUtility_h

#include <FS.h>

namespace FSUtil
{
	void recursiveDelete(FS &fs, File &root);
	bool isChildOf(const String &parent, const String &child);
} // namespace FSUt

#endif // _FilesystemUtility_h
