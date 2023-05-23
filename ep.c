#include <stdio.h>

// Constants for motor control
#define PI 3.14159265358979323846
#define POLE_PAIRS 2
#define MAX_VOLTAGE 24.0

// Function prototypes
double magnetic_field_orientation_control(double id_ref, double iq_ref, double theta);
double sensorless_speed_control(double id_ref, double iq_ref, double theta);

int main() {
    double id_ref = 0.0; // Reference d-axis current
    double iq_ref = 1.0; // Reference q-axis current
    double theta = 0.0;  // Rotor angle

    double voltage = magnetic_field_orientation_control(id_ref, iq_ref, theta);
    printf("Magnetic Field Orientation Control Voltage: %f\n", voltage);

    voltage = sensorless_speed_control(id_ref, iq_ref, theta);
    printf("Sensorless Speed Control Voltage: %f\n", voltage);

    return 0;
}

// Magnetic Field Orientation Control function
double magnetic_field_orientation_control(double id_ref, double iq_ref, double theta) {
    double voltage = MAX_VOLTAGE * (id_ref * cos(theta) + iq_ref * sin(theta));
    return voltage;
}

// Sensorless Speed Control function
double sensorless_speed_control(double id_ref, double iq_ref, double theta) {
    double voltage = MAX_VOLTAGE * (id_ref * cos(theta) - iq_ref * sin(theta));
    return voltage;
}
