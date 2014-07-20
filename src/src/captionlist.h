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
#ifndef CAPTIONLIST_H
#define CAPTIONLIST_H

#include <QObject>
#include <QQmlListProperty>
#include "captiontest.h"

class CaptionList : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<CaptionTest> captions READ captions)
    Q_PROPERTY(QString datafile READ datafile WRITE setDatafile NOTIFY datafileChanged)
    Q_PROPERTY(int captionCount READ captionCount NOTIFY captionCountChanged)
    Q_PROPERTY(int loadStartRow MEMBER m_loadStartRow)
    Q_PROPERTY(int loadStartColumn MEMBER m_loadStartColumn)
public:
    explicit CaptionList(QObject *parent = 0);
    QQmlListProperty<CaptionTest> captions();
    ~CaptionList();

signals:
    void datafileChanged();
    void captionCountChanged();

public slots:
    QString datafile();
    void setDatafile(QString value);
    int captionCount();
    bool saveResult();
    bool loadCaptionData();

private:
    QList<CaptionTest *> m_captions;
    QString m_datafile;
    int m_loadStartRow;
    int m_loadStartColumn;
};

#endif // CAPTIONLIST_H
