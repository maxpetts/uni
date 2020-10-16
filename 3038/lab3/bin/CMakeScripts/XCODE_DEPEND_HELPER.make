# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.celsius2fahrenheit.Debug:
/Users/mp/Documents/uni/3038/lab3/bin/Debug/celsius2fahrenheit:
	/bin/rm -f /Users/mp/Documents/uni/3038/lab3/bin/Debug/celsius2fahrenheit


PostBuild.lab3-1-cxx.Debug:
/Users/mp/Documents/uni/3038/lab3/bin/Debug/lab3-1-cxx:
	/bin/rm -f /Users/mp/Documents/uni/3038/lab3/bin/Debug/lab3-1-cxx


PostBuild.lab3-2-cxx.Debug:
/Users/mp/Documents/uni/3038/lab3/bin/Debug/lab3-2-cxx:
	/bin/rm -f /Users/mp/Documents/uni/3038/lab3/bin/Debug/lab3-2-cxx


PostBuild.lab3-3-cxx.Debug:
/Users/mp/Documents/uni/3038/lab3/bin/Debug/lab3-3-cxx:
	/bin/rm -f /Users/mp/Documents/uni/3038/lab3/bin/Debug/lab3-3-cxx


PostBuild.lab3-4-cxx.Debug:
/Users/mp/Documents/uni/3038/lab3/bin/Debug/lab3-4-cxx:
	/bin/rm -f /Users/mp/Documents/uni/3038/lab3/bin/Debug/lab3-4-cxx


PostBuild.lab3-5-cxx.Debug:
/Users/mp/Documents/uni/3038/lab3/bin/Debug/lab3-5-cxx:
	/bin/rm -f /Users/mp/Documents/uni/3038/lab3/bin/Debug/lab3-5-cxx


PostBuild.celsius2fahrenheit.Release:
/Users/mp/Documents/uni/3038/lab3/bin/Release/celsius2fahrenheit:
	/bin/rm -f /Users/mp/Documents/uni/3038/lab3/bin/Release/celsius2fahrenheit


PostBuild.lab3-1-cxx.Release:
/Users/mp/Documents/uni/3038/lab3/bin/Release/lab3-1-cxx:
	/bin/rm -f /Users/mp/Documents/uni/3038/lab3/bin/Release/lab3-1-cxx


PostBuild.lab3-2-cxx.Release:
/Users/mp/Documents/uni/3038/lab3/bin/Release/lab3-2-cxx:
	/bin/rm -f /Users/mp/Documents/uni/3038/lab3/bin/Release/lab3-2-cxx


PostBuild.lab3-3-cxx.Release:
/Users/mp/Documents/uni/3038/lab3/bin/Release/lab3-3-cxx:
	/bin/rm -f /Users/mp/Documents/uni/3038/lab3/bin/Release/lab3-3-cxx


PostBuild.lab3-4-cxx.Release:
/Users/mp/Documents/uni/3038/lab3/bin/Release/lab3-4-cxx:
	/bin/rm -f /Users/mp/Documents/uni/3038/lab3/bin/Release/lab3-4-cxx


PostBuild.lab3-5-cxx.Release:
/Users/mp/Documents/uni/3038/lab3/bin/Release/lab3-5-cxx:
	/bin/rm -f /Users/mp/Documents/uni/3038/lab3/bin/Release/lab3-5-cxx


PostBuild.celsius2fahrenheit.MinSizeRel:
/Users/mp/Documents/uni/3038/lab3/bin/MinSizeRel/celsius2fahrenheit:
	/bin/rm -f /Users/mp/Documents/uni/3038/lab3/bin/MinSizeRel/celsius2fahrenheit


PostBuild.lab3-1-cxx.MinSizeRel:
/Users/mp/Documents/uni/3038/lab3/bin/MinSizeRel/lab3-1-cxx:
	/bin/rm -f /Users/mp/Documents/uni/3038/lab3/bin/MinSizeRel/lab3-1-cxx


PostBuild.lab3-2-cxx.MinSizeRel:
/Users/mp/Documents/uni/3038/lab3/bin/MinSizeRel/lab3-2-cxx:
	/bin/rm -f /Users/mp/Documents/uni/3038/lab3/bin/MinSizeRel/lab3-2-cxx


PostBuild.lab3-3-cxx.MinSizeRel:
/Users/mp/Documents/uni/3038/lab3/bin/MinSizeRel/lab3-3-cxx:
	/bin/rm -f /Users/mp/Documents/uni/3038/lab3/bin/MinSizeRel/lab3-3-cxx


PostBuild.lab3-4-cxx.MinSizeRel:
/Users/mp/Documents/uni/3038/lab3/bin/MinSizeRel/lab3-4-cxx:
	/bin/rm -f /Users/mp/Documents/uni/3038/lab3/bin/MinSizeRel/lab3-4-cxx


PostBuild.lab3-5-cxx.MinSizeRel:
/Users/mp/Documents/uni/3038/lab3/bin/MinSizeRel/lab3-5-cxx:
	/bin/rm -f /Users/mp/Documents/uni/3038/lab3/bin/MinSizeRel/lab3-5-cxx


PostBuild.celsius2fahrenheit.RelWithDebInfo:
/Users/mp/Documents/uni/3038/lab3/bin/RelWithDebInfo/celsius2fahrenheit:
	/bin/rm -f /Users/mp/Documents/uni/3038/lab3/bin/RelWithDebInfo/celsius2fahrenheit


PostBuild.lab3-1-cxx.RelWithDebInfo:
/Users/mp/Documents/uni/3038/lab3/bin/RelWithDebInfo/lab3-1-cxx:
	/bin/rm -f /Users/mp/Documents/uni/3038/lab3/bin/RelWithDebInfo/lab3-1-cxx


PostBuild.lab3-2-cxx.RelWithDebInfo:
/Users/mp/Documents/uni/3038/lab3/bin/RelWithDebInfo/lab3-2-cxx:
	/bin/rm -f /Users/mp/Documents/uni/3038/lab3/bin/RelWithDebInfo/lab3-2-cxx


PostBuild.lab3-3-cxx.RelWithDebInfo:
/Users/mp/Documents/uni/3038/lab3/bin/RelWithDebInfo/lab3-3-cxx:
	/bin/rm -f /Users/mp/Documents/uni/3038/lab3/bin/RelWithDebInfo/lab3-3-cxx


PostBuild.lab3-4-cxx.RelWithDebInfo:
/Users/mp/Documents/uni/3038/lab3/bin/RelWithDebInfo/lab3-4-cxx:
	/bin/rm -f /Users/mp/Documents/uni/3038/lab3/bin/RelWithDebInfo/lab3-4-cxx


PostBuild.lab3-5-cxx.RelWithDebInfo:
/Users/mp/Documents/uni/3038/lab3/bin/RelWithDebInfo/lab3-5-cxx:
	/bin/rm -f /Users/mp/Documents/uni/3038/lab3/bin/RelWithDebInfo/lab3-5-cxx




# For each target create a dummy ruleso the target does not have to exist
