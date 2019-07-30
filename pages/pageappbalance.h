/*
    Copyright 2016 - 2017 Benjamin Vedder	benjamin@vedder.se

    This file is part of VESC Tool.

    VESC Tool is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    VESC Tool is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
    */

#ifndef PAGEAPPBALANCE_H
#define PAGEAPPBALANCE_H

#include <QWidget>
#include <QVector>
#include <QTimer>
#include "vescinterface.h"

namespace Ui {
class PageAppBalance;
}

class PageAppBalance : public QWidget
{
    Q_OBJECT

public:
    explicit PageAppBalance(QWidget *parent = 0);
    ~PageAppBalance();

    VescInterface *vesc() const;
    void setVesc(VescInterface *vesc);

private slots:
    void timerSlot();
    void appValuesReceived(double pid_outpout, double pitch, double roll, uint32_t diff_time, double motor_current, double motor_position);

private:
    Ui::PageAppBalance *ui;
    VescInterface *mVesc;

    QTimer *mTimer;

    bool mUpdatePlots;

    QVector<double> mAppPidOutputVec;
    QVector<double> mAppPitchVec;
    QVector<double> mAppRollVec;
    QVector<uint32_t> mAppDiffTimeVec;
    QVector<double> mAppMotorCurrentVec;
    QVector<double> mAppMotorPositionVec;

    QVector<double> mSeconds;

    double mSecondCounter;
    qint64 mLastUpdateTime;

    void appendDoubleAndTrunc(QVector<double> *vec, double num, int maxSize);
    void appendUint32tAndTrunc(QVector<uint32_t> *vec, uint32_t num, int maxSize);

};

#endif // PAGEAPPNRF_H
