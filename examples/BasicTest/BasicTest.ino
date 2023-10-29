#include "src/FilesystemUtility.h"

void setup()
{
	Serial.begin(115200);

	const String parent = "/parent";
	const String child = "/parent/child";
	const String child2 = "/parent/child/child2";
	const String flaseChild = "/parentchild";
	const String falseChild2 = "/child";
	const String falseChild3 = "/";
	const String parent2 = "/parent2/";

	const String children[] = {child, child2, flaseChild, falseChild2, falseChild3, parent2};

	for (const String &child : children)
	{
		Serial.printf("isChildOf(\"%s\", \"%s\") = %s\n", parent.c_str(), child.c_str(), FSUtil::isChildOf(parent, child) ? "true" : "false");
	}

	for (const String &child : children)
	{
		Serial.printf("parentPath(\"%s\") = \"%s\"\n", child.c_str(), FSUtil::parentPath(child).c_str());
	}
}

void loop() {}