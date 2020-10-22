# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.TestInteger.Debug:
/Users/mp/Documents/uni/3038/lab4/bin/Debug/TestInteger:
	/bin/rm -f /Users/mp/Documents/uni/3038/lab4/bin/Debug/TestInteger


PostBuild.TestStringInv.Debug:
/Users/mp/Documents/uni/3038/lab4/bin/Debug/TestStringInv:
	/bin/rm -f /Users/mp/Documents/uni/3038/lab4/bin/Debug/TestStringInv


PostBuild.TestInteger.Release:
/Users/mp/Documents/uni/3038/lab4/bin/Release/TestInteger:
	/bin/rm -f /Users/mp/Documents/uni/3038/lab4/bin/Release/TestInteger


PostBuild.TestStringInv.Release:
/Users/mp/Documents/uni/3038/lab4/bin/Release/TestStringInv:
	/bin/rm -f /Users/mp/Documents/uni/3038/lab4/bin/Release/TestStringInv


PostBuild.TestInteger.MinSizeRel:
/Users/mp/Documents/uni/3038/lab4/bin/MinSizeRel/TestInteger:
	/bin/rm -f /Users/mp/Documents/uni/3038/lab4/bin/MinSizeRel/TestInteger


PostBuild.TestStringInv.MinSizeRel:
/Users/mp/Documents/uni/3038/lab4/bin/MinSizeRel/TestStringInv:
	/bin/rm -f /Users/mp/Documents/uni/3038/lab4/bin/MinSizeRel/TestStringInv


PostBuild.TestInteger.RelWithDebInfo:
/Users/mp/Documents/uni/3038/lab4/bin/RelWithDebInfo/TestInteger:
	/bin/rm -f /Users/mp/Documents/uni/3038/lab4/bin/RelWithDebInfo/TestInteger


PostBuild.TestStringInv.RelWithDebInfo:
/Users/mp/Documents/uni/3038/lab4/bin/RelWithDebInfo/TestStringInv:
	/bin/rm -f /Users/mp/Documents/uni/3038/lab4/bin/RelWithDebInfo/TestStringInv




# For each target create a dummy ruleso the target does not have to exist
