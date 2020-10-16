# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.lab2-1-c.Debug:
/Users/mp/Documents/uni/3038/lab2/bin/Debug/lab2-1-c:
	/bin/rm -f /Users/mp/Documents/uni/3038/lab2/bin/Debug/lab2-1-c


PostBuild.lab2-1-cxx.Debug:
/Users/mp/Documents/uni/3038/lab2/bin/Debug/lab2-1-cxx:
	/bin/rm -f /Users/mp/Documents/uni/3038/lab2/bin/Debug/lab2-1-cxx


PostBuild.lab2-2-c.Debug:
/Users/mp/Documents/uni/3038/lab2/bin/Debug/lab2-2-c:
	/bin/rm -f /Users/mp/Documents/uni/3038/lab2/bin/Debug/lab2-2-c


PostBuild.lab2-2-cxx.Debug:
/Users/mp/Documents/uni/3038/lab2/bin/Debug/lab2-2-cxx:
	/bin/rm -f /Users/mp/Documents/uni/3038/lab2/bin/Debug/lab2-2-cxx


PostBuild.lab2-3-cxx.Debug:
/Users/mp/Documents/uni/3038/lab2/bin/Debug/lab2-3-cxx:
	/bin/rm -f /Users/mp/Documents/uni/3038/lab2/bin/Debug/lab2-3-cxx


PostBuild.lab2-1-c.Release:
/Users/mp/Documents/uni/3038/lab2/bin/Release/lab2-1-c:
	/bin/rm -f /Users/mp/Documents/uni/3038/lab2/bin/Release/lab2-1-c


PostBuild.lab2-1-cxx.Release:
/Users/mp/Documents/uni/3038/lab2/bin/Release/lab2-1-cxx:
	/bin/rm -f /Users/mp/Documents/uni/3038/lab2/bin/Release/lab2-1-cxx


PostBuild.lab2-2-c.Release:
/Users/mp/Documents/uni/3038/lab2/bin/Release/lab2-2-c:
	/bin/rm -f /Users/mp/Documents/uni/3038/lab2/bin/Release/lab2-2-c


PostBuild.lab2-2-cxx.Release:
/Users/mp/Documents/uni/3038/lab2/bin/Release/lab2-2-cxx:
	/bin/rm -f /Users/mp/Documents/uni/3038/lab2/bin/Release/lab2-2-cxx


PostBuild.lab2-3-cxx.Release:
/Users/mp/Documents/uni/3038/lab2/bin/Release/lab2-3-cxx:
	/bin/rm -f /Users/mp/Documents/uni/3038/lab2/bin/Release/lab2-3-cxx


PostBuild.lab2-1-c.MinSizeRel:
/Users/mp/Documents/uni/3038/lab2/bin/MinSizeRel/lab2-1-c:
	/bin/rm -f /Users/mp/Documents/uni/3038/lab2/bin/MinSizeRel/lab2-1-c


PostBuild.lab2-1-cxx.MinSizeRel:
/Users/mp/Documents/uni/3038/lab2/bin/MinSizeRel/lab2-1-cxx:
	/bin/rm -f /Users/mp/Documents/uni/3038/lab2/bin/MinSizeRel/lab2-1-cxx


PostBuild.lab2-2-c.MinSizeRel:
/Users/mp/Documents/uni/3038/lab2/bin/MinSizeRel/lab2-2-c:
	/bin/rm -f /Users/mp/Documents/uni/3038/lab2/bin/MinSizeRel/lab2-2-c


PostBuild.lab2-2-cxx.MinSizeRel:
/Users/mp/Documents/uni/3038/lab2/bin/MinSizeRel/lab2-2-cxx:
	/bin/rm -f /Users/mp/Documents/uni/3038/lab2/bin/MinSizeRel/lab2-2-cxx


PostBuild.lab2-3-cxx.MinSizeRel:
/Users/mp/Documents/uni/3038/lab2/bin/MinSizeRel/lab2-3-cxx:
	/bin/rm -f /Users/mp/Documents/uni/3038/lab2/bin/MinSizeRel/lab2-3-cxx


PostBuild.lab2-1-c.RelWithDebInfo:
/Users/mp/Documents/uni/3038/lab2/bin/RelWithDebInfo/lab2-1-c:
	/bin/rm -f /Users/mp/Documents/uni/3038/lab2/bin/RelWithDebInfo/lab2-1-c


PostBuild.lab2-1-cxx.RelWithDebInfo:
/Users/mp/Documents/uni/3038/lab2/bin/RelWithDebInfo/lab2-1-cxx:
	/bin/rm -f /Users/mp/Documents/uni/3038/lab2/bin/RelWithDebInfo/lab2-1-cxx


PostBuild.lab2-2-c.RelWithDebInfo:
/Users/mp/Documents/uni/3038/lab2/bin/RelWithDebInfo/lab2-2-c:
	/bin/rm -f /Users/mp/Documents/uni/3038/lab2/bin/RelWithDebInfo/lab2-2-c


PostBuild.lab2-2-cxx.RelWithDebInfo:
/Users/mp/Documents/uni/3038/lab2/bin/RelWithDebInfo/lab2-2-cxx:
	/bin/rm -f /Users/mp/Documents/uni/3038/lab2/bin/RelWithDebInfo/lab2-2-cxx


PostBuild.lab2-3-cxx.RelWithDebInfo:
/Users/mp/Documents/uni/3038/lab2/bin/RelWithDebInfo/lab2-3-cxx:
	/bin/rm -f /Users/mp/Documents/uni/3038/lab2/bin/RelWithDebInfo/lab2-3-cxx




# For each target create a dummy ruleso the target does not have to exist
