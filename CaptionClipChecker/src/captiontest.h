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
#ifndef CAPTIONTEST_H
#define CAPTIONTEST_H

#include <QObject>

class CaptionTest : public QObject
{
    Q_OBJECT
//    Q_PROPERTY(QString caption MEMBER m_caption NOTIFY captionChanged)
    Q_PROPERTY(QString caption READ caption WRITE setCaption NOTIFY captionChanged)
//    Q_PROPERTY(QString datafile READ datafile WRITE setDatafile NOTIFY datafileChanged)
//    Q_PROPERTY(bool result MEMBER m_result)
    Q_PROPERTY(QString result READ result WRITE setResult)
//    Q_PROPERTY(bool result READ result WRITE setResult)
public:
    explicit CaptionTest(QObject *parent = 0);
    CaptionTest(QString caption, QObject *parent = 0);
    QString caption();
    void setCaption(QString value);
    QString result();
    void setResult(QString value);

signals:
    void captionChanged();

public slots:

private:
    QString         m_caption;
    QString         m_result;
};

#endif // CAPTIONTEST_H
