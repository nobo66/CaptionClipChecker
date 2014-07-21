/****************************************************************************
** Copyright (c) 2014, CaptionClipChecker Project
** All rights reserved.
**
** Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are met:
**
** 1. Redistributions of source code must retain the above copyright notice,
** this list of conditions and the following disclaimer.
**
** 2. Redistributions in binary form must reproduce the above copyright notice,
** this list of conditions and the following disclaimer in the documentation and/or
** other materials provided with the distribution.
**
** 3. Neither the name of the copyright holder nor the names of its contributors
** may be used to endorse or promote products derived from this software without
** specific prior written permission.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
** ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
** WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
** IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY
** DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
** (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
** LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
** NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
** EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
****************************************************************************/
import QtQuick 2.2
import QtQuick.Controls 1.1
import QtQuick.Dialogs 1.1
import QtQuick.Layouts 1.1
import com.nobo66.captionchecker 1.0

ApplicationWindow {
    id:root
    visible: true
    width: 640
    height: 480
    title: qsTr("CaptionClipChecker")

    menuBar: MenuBar {
        Menu {
            title: qsTr("&File")
            MenuItem {
                text: qsTr("E&xit")
                onTriggered: Qt.quit();
            }
            MenuItem { action: openAction }
            MenuItem { action: checkAction }
            MenuItem { action: reloadAction }
        }
    }

    ColumnLayout{
        spacing: 5
        anchors.fill: parent
        Row{
            id:sample_texts
            Label{
                text:qsTr("caption clip is checked using this text element. -->")
            }

            Text{
                id:txt_caption_checker01
                text: "sample caption"
                width: 80
                height: 50
                elide: Text.ElideRight
                maximumLineCount: 2
                //        wrapMode: Text.WrapAnywhere
                Rectangle{
                    anchors.fill: parent
                    color: "steelblue"
                    opacity: 0.3
                }
            }
        }
        Row{
            Label { text:qsTr("quick check. input any strings. -->") }
            TextArea {
                onTextChanged: {
                    txt_caption_checker01.text = text
                    if(txt_caption_checker01.truncated){
                        ta_log.append("NG:cpation is clipped.")
                    }
                    else{
                        ta_log.append("OK:cpation is not clipped.")
                    }
                }
            }

        }

        Row{
            spacing: 5
            Button { action: openAction }
            Button { action: checkAction }
            Button { action: reloadAction }
        }
        Row{
            spacing: 5
            Label{
                id:txt_startcell_setting
                text:qsTr("caption list position in data file:")
            }
            Label{text:qsTr("Column")}
            TextField{
                id:tf_startcell_setting_col
                width: 30
                height: txt_startcell_setting.height
                text:cl01.loadStartColumn
                onAccepted: {
                    cl01.loadStartColumn = text
                }
            }
            Label{text:qsTr("Row")}
            TextField{
                id:tf_startcell_setting_row
                width: 30
                height: txt_startcell_setting.height
                text:cl01.loadStartRow
                onAccepted: {
                    cl01.loadStartRow = text
                }
            }
            Button { action: applyCaptionListPositionSettingsAction }
        }
        TextArea{
            id:ta_log
            readOnly: true
            Layout.fillWidth: true
            Layout.fillHeight: true
        }
    }

    CaptionList{
        id:cl01
//        loadStartColumn: 2
//        loadStartRow: 2
        function checkCaptionClip(){
            var temp_caption
            var ok_count = 0
            var ng_count = 0
            var ret = false
            txt_caption_checker01.text = " "
            for(var i=0; i<cl01.captionCount; i++){
                temp_caption = cl01.captions[i].caption
                txt_caption_checker01.text = temp_caption
                if(txt_caption_checker01.truncated){
                    cl01.captions[i].result = "NG"
                    ng_count++
                }
                else{
                    cl01.captions[i].result = "OK"
                    ok_count++
                }
                console.log("caption:"+temp_caption+"\t\t\ttxt_caption_checker01.truncated="+txt_caption_checker01.truncated)
                ta_log.append(cl01.captions[i].caption+"\t\t:"+cl01.captions[i].result)
                txt_caption_checker01.text = " "
            }
            ret = cl01.saveResult()
            txt_caption_checker01.text = "finished"
            ta_log.append("Caption clip check completed.")
            ta_log.append("NG(clipped):"+ng_count+"\t OK(not clipped):"+ok_count+"\t Total:"+cl01.captionCount)
            if(ret === true){
                ta_log.append("Results were written to the date file.")
                ta_log.append("file path:"+cl01.datafile)
            }
            else{
                ta_log.append("failed to seve result. close data file and try again.")
            }
        }
    }
    FileDialog {
        id: fileDialog
        title: qsTr("Please choose a file")
        nameFilters: [ "xlsx file (*.xlsx)", "All files (*)" ]
        onAccepted: {
            cl01.datafile = fileUrl
            ta_log.append("data file loaded.")
            ta_log.append("file path:"+cl01.datafile)
        }
    }
    Action {
        id: openAction
        text: qsTr("&Open data file")
        shortcut: "Ctrl+O"
        onTriggered: fileDialog.open()
        tooltip: qsTr("Open caption data file(.xlsx)  Ctrl+O")
    }
    Action {
        id: checkAction
        text: qsTr("Check caption clip")
        shortcut: "Alt+C"
        onTriggered: cl01.checkCaptionClip()
        tooltip: qsTr("Check caption clipped or not.  Alt+C")
    }
    Action {
        id: reloadAction
        text: qsTr("&Reload data file")
        shortcut: "Ctrl+R"
        onTriggered: {
            cl01.loadCaptionData()
            ta_log.append("data file reloaded.")
            ta_log.append("file path:"+cl01.datafile)
        }
        tooltip: qsTr("Reloatd loaded data file.  Ctrl+R")
    }
    Action {
        id: applyCaptionListPositionSettingsAction
        text: qsTr("Apply")
        onTriggered: {
            cl01.loadStartColumn = tf_startcell_setting_col.text
            cl01.loadStartRow = tf_startcell_setting_row.text
        }

        tooltip: qsTr("Apply caption list position settigs.")
    }
}
