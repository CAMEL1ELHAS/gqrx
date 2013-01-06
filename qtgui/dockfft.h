/* -*- c++ -*- */
/*
 * Copyright 2011-2013 Alexandru Csete OZ9AEC.
 *
 * Gqrx is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * Gqrx is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Gqrx; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */
#ifndef DOCKFFT_H
#define DOCKFFT_H

#include <QDockWidget>
#include <QSettings>

namespace Ui {
    class DockFft;
}


/*! \brief Dock widget with FFT settings. */
class DockFft : public QDockWidget
{
    Q_OBJECT

public:
    explicit DockFft(QWidget *parent = 0);
    ~DockFft();

    int fftRate();
    int setFftRate(int fft_rate);

    int fftSize();
    int setFftSize(int fft_size);

    void saveSettings(QSettings *settings);
    void readSettings(QSettings *settings);

    enum fftFilterType
    {
        FILTER_TYPE_NONLIN,
        FILTER_TYPE_LIN,
        FILTER_TYPE_FIXED,
        FILTER_TYPE_NONE
    };

signals:
    void fftSizeChanged(int size);  /*! \brief FFT size changed. */
    void fftRateChanged(int fps);   /*! \brief FFT rate changed. */
    void fftSplitChanged(int pct);  /*! \brief Split between pandapter and waterfall changed. */
    void fftFilterTypeChanged(int type);  /*! \brief FFT video filter type has changed. */
    void fftFilterGainChanged(double gain);  /*! \brief FFT video filter gain has changed. */

private slots:
    void on_fftSizeComboBox_currentIndexChanged(const QString & text);
    void on_fftRateComboBox_currentIndexChanged(const QString & text);
    void on_fftSplitSlider_valueChanged(int value);
    void on_fftFilterTypeCombo_currentIndexChanged(int index);
    void on_fftFilterGainSlider_valueChanged(int value);

private:
    Ui::DockFft *ui;
};

#endif // DOCKFFT_H
