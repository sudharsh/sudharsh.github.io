---
author: sudharsh
comments: true
date: 2007-07-24 17:30
layout: post
slug: adding-packages-to-the-openmoko-image
title: Adding packages to the Openmoko image
wordpress_id: 67
categories:
- openmoko
- Tips
---

Here's a pretty trivial script I wrote to inject packages into the openmoko images. sed does all the dirty work for me. I was feeling pretty lazy to edit the task-openmoko.bb each and everytime after it gets reverted after an svn update. So came up with this hack.

The trick is, task-openmoko.bb in oe/packages/tasks contains the list of the apps that will be included in the final image. If your app name is not present in it, your recipe will be parsed correctly and your app will build, but it wont make it to the final image.

Note: Bump up PR in task-openmoko.bb before using the script.

``` bash
#!/bin/bash
# Sudharshan "Sup3rkiddo" S
# inject, script that injects packages into the OpenMoko standard,
# The sed line does all the stuff, nothing elite...
# The package is grouped under TASK_OPENMOKO_LINUX..after rsync
# The bitbake recipes should be present in the proper place. OE docs for info
ARGS=1
E_BADARGS=65
if [ $# -ne "$ARGS" ]
then
echo "Usage: inject "
exit $E_BADARGS
fi
make update
make setup
cd oe/packages/tasks
mv task-openmoko.bb task-openmoko.bb_bakup
# search for rsync and append the package name after it..[KIDDISH HACK]
sed '/rsync \\/ a\ '$1' \\' >task-openmoko.bb
mv task-openmoko.bb_bakup ~/
cd ../../../
#make clean-package-$1
make build-package-$1
echo "Done injection..muhahah"
```
You still have to make sure you have the bitbake recipes in the proper place. As always I am not responsible for dead kittens caused due to the usage of the above script ;)

Links:
[ http://bec-systems.com/web/content/view/59/9/](http://www.bec-systems.com/web/content/view/59/9/)
