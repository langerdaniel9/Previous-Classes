/*
 * Daniel Langer
 * 114662901
 */

abstract class Vehicle {
    private String ownersName = "";
    private int vehicleNumber;

    protected Vehicle(String initOwnersName, int initVehicleNumber) {
        ownersName = initOwnersName;
        vehicleNumber = initVehicleNumber;
    }

    public String getOwnersName() {
        return ownersName;
    }

    public int getVehicleNumber() {
        return vehicleNumber;
    }
}

class Bicycle extends Vehicle {
    public Bicycle(String initOwnersName, int initVehicleNumber) {
        super(initOwnersName, initVehicleNumber);
    }
}

class MotorizedVehicle extends Vehicle {
    private int EngineVolumeDisplacement;
    private int numberOfWheels;

    public MotorizedVehicle(String initOwnersName, int initVehicleNumber, int initEngineVolumeDisplacement,
            int initNumberOfWheels) {
        super(initOwnersName, initVehicleNumber);
        EngineVolumeDisplacement = initEngineVolumeDisplacement;
        numberOfWheels = initNumberOfWheels;
    }

    public int getEngineVolumeDisplacement() {
        return EngineVolumeDisplacement;
    }

    public int getNumberOfWheels() {
        return numberOfWheels;
    }

    public int getHorsePower() {
        return EngineVolumeDisplacement * numberOfWheels;
    }
}

public class TestAbstractVehicle {
    public static void main(String[] args) {
        Bicycle myBike = new Bicycle("Daniel", 123);
        System.out.println(
                "Bike:\nOwnersName = " + myBike.getOwnersName() + "\nVehicleNumber = " + myBike.getVehicleNumber());

        System.out.println();

        MotorizedVehicle myCar = new MotorizedVehicle("Daniel", 1234, 14, 4);
        System.out.println("Motorized Vehicle:\nOwnersName = " + myCar.getOwnersName() + "\nVehicleNumber = "
                + myCar.getVehicleNumber() + "\nEngineVolumeDisplacement = " + myCar.getEngineVolumeDisplacement()
                + "\nNumberOfWheels = " + myCar.getNumberOfWheels() + "\nHorsePower = " + myCar.getHorsePower());
    }
}
