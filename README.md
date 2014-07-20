#What is CaptionClipChecker?
CaptionClipChecker is a test tool that checks the caption(string)
is clipped or not by the specific QML Text element. 
Captions can be defined by .xlsx file and the results are written to it.

#System requirements
*Qt5.2.0 or later


#Tested environment
*Qt5.3.0 on Mac OS X Mavericks 10.9.2
*Qt5.2.1 and Qt5.3.0 on Windows7 64bit
*Qt5.3.0 on Gentoo Linux 64bit


#Build and run
*Open src/CaptionClipChecker.pro by Qt Creator.
*Select Build->Build Project "CaptionClipChecker" (Ctrl+B).
*Select Build->Run(Ctrl+R).


#Questions/Issues/Comments
Questions, Issues and Comments can be emailed to 
noboru.murakami@gmail.com


#Known issues


#.xlsx access library
Using QtXlsxWriter to read/write .xlsx(Excel) formatted file.
https://github.com/dbzhang800/QtXlsxWriter
Thanks to Debao Zhang.


#Revision history
*Version 0.50(bata)
 Initial release.
