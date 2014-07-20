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
#include "captionlist.h"
#include "xlsxdocument.h"

#define END_OF_DATA_CHECK_COUNT 5
#define MAX_CAPTIONS 32767

CaptionList::CaptionList(QObject *parent) :
    QObject(parent)
  ,m_loadStartRow(2)
  ,m_loadStartColumn(1)
{
}

QQmlListProperty<CaptionTest> CaptionList::captions()
{
    return QQmlListProperty<CaptionTest>(this, m_captions);
}

CaptionList::~CaptionList()
{
    m_captions.clear();
}

QString CaptionList::datafile()
{
    return m_datafile;
}

void CaptionList::setDatafile(QString value)
{
    if(m_datafile !=value){
        m_datafile = value;
#if defined Q_OS_WIN
        m_datafile.remove("file:///");
#else
        m_datafile.remove("file://");
#endif
        loadCaptionData();
    }

}

int CaptionList::captionCount()
{
 return m_captions.count();
}

bool CaptionList::saveResult()
{
    QXlsx::Document xlsx(m_datafile);
    int tempRow = m_loadStartRow;
    bool bRet = false;
    for(int i=0; i<m_captions.count(); i++){
        bRet = xlsx.write(tempRow,m_loadStartColumn+1,m_captions.at(i)->result());
        tempRow++;
    }
    bRet = xlsx.save();
    return bRet;
}

bool CaptionList::loadCaptionData()
{
    QXlsx::Document xlsx(m_datafile);
    CaptionTest *caption;
    int spaceRowCount = 0;
    int tempRow = m_loadStartRow;
    m_captions.clear();
    for(int i=0; i<MAX_CAPTIONS; i++){
        QString tempStr;
        tempStr = (xlsx.read(tempRow,m_loadStartColumn)).toString();
        caption = new CaptionTest(tempStr);
        m_captions.append(caption);
        if(tempStr.isNull()){
            spaceRowCount++;
            if(spaceRowCount > END_OF_DATA_CHECK_COUNT){
                break;
            }
        }else{
            spaceRowCount = 0;
        }
        tempRow++;
    }
    emit captionCountChanged();
    return xlsx.save();
}
