#ifndef BLINKLED_H
#define BLINKLED_H
#include <QWidget>

class GUI : public QWidget
{



public:
    /** Constructor. Builds the ATM GUI Window
         *
         *  @param ap_theSimulation pointer to the simulation object
         */
    explicit ATMMainWindow(simulation::Simulation *ap_theSimulation= nullptr);
    /** Destructor.
        */
    ~ATMMainWindow() override;
    /** Access functions to the recommended size for the widget
        */
    QSize sizeHint() const override;

private slots:

protected:

private:

};


#endif // BLINKLED_H
