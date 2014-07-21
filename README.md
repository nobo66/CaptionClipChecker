# CaptionClipChecker
## What is CaptionClipChecker?
CaptionClipChecker is a test tool that checks the caption(string)
is clipped or not by the specific QML Text element. 
Captions can be defined by .xlsx file and the results are written to it.

## System requirements
* Qt5.2.0 or later


## Tested environment
* Qt5.3.0 on Mac OS X Mavericks 10.9.2
* Qt5.2.1 and Qt5.3.0 on Windows7 64bit
* Qt5.3.0 on Gentoo Linux 64bit


## Build and run
* Open src/CaptionClipChecker.pro by Qt Creator.
* Select Build->Build Project "CaptionClipChecker" (Ctrl+B).
* Select Build->Run(Ctrl+R).


## How to use
* Create caption list as .xlsx format.
* Modify checker text element's(id=txt_caption_checker01) property as you want.
 * Checker text element is defined in main.qml.
* Run CaptionClipChecker.
* Open .xlsx file you created(Ctrl+O).
* Execute check(Alt+C).
* Open .xlsx file by Excel(or alternative application) and check the results.
* If you update caption list, you can reload it by Ctrl+R


## Questions/Issues/Comments
Questions, Issues and Comments can be emailed to 
noboru.murakami@gmail.com


## Known issues


## Trouble shooting
* Failed to save result
 * Check if the .xlsx file is opened by other application.(ex. Excel)


## .xlsx access library
Using QtXlsxWriter to read/write .xlsx(Excel) formatted file.
https://github.com/dbzhang800/QtXlsxWriter
Thanks to Debao Zhang.


## Revision history
* Version 0.50(bata)
 * Initial release.
