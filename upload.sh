#!/bin/sh

preparation="prepare_upload.sh"
if [ -x ${preparation} ]
then
	bash ${preparation}
fi

comment=".."
GIT=`which git`

$GIT add --all
$GIT commit -m ${comment}
$GIT push
wait

ending="ending_upload.sh"
if [ -x ${ending} ]
then
	bash ${ending}
fi
