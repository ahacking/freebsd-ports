Index: main.cpp
@@ -82,7 +82,7 @@
 static void help()
 {
   printf(
-  "DGen/SDL v"VER"\n"
+  "DGen/SDL v" VER "\n"
   "Usage: dgen [options] [romname [...]]\n\n"
   "Where options are:\n"
   "    -v              Print version number and exit.\n"
@@ -256,7 +256,7 @@
 	{
 	case 'v':
 	  // Show version and exit
-	  printf("DGen/SDL version "VER"\n");
+	  printf("DGen/SDL version " VER "\n");
 	  return 0;
 	case 'r':
 	  // Parse another RC file or stdin
