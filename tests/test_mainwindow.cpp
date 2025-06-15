#include <QtTest>
#include "mainwindow.h"

class MainWindowTest : public QObject {
    Q_OBJECT
private slots:
    void testWindowTitle();
};

void MainWindowTest::testWindowTitle() {
    MainWindow w;
    QCOMPARE(w.windowTitle(), QString("Прогноз погоды"));  // Заменить на фактический заголовок
}

QTEST_MAIN(MainWindowTest)

#include "test_mainwindow.moc"
