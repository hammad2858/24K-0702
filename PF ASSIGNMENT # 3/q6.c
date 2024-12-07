#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Weather {
    float temperature;
    float rainfall;
    float windSpeed;
} Weather;

typedef struct Crop {
    char cropType[50];
    char growthStage[50];
    float expectedYield;
    Weather* weatherForecast;
} Crop;

typedef struct Equipment {
    char equipmentType[50];
    char operationalStatus[50];
    float fuelLevel;
    char activitySchedule[100];
} Equipment;

typedef struct Sensor {
    float soilNutrients;
    float pHLevel;
    int pestActivity;
} Sensor;

typedef struct Field {
    float gpsCoordinates[2];
    float soilHealthMetrics;
    float moistureLevel;
    Crop* crops;
    int numCrops;
    Equipment* equipment;
    int numEquipment;
    Sensor* sensors;
    int numSensors;
} Field;

typedef struct RegionalHub {
    Field* fields;
    int numFields;
    float aggregateYieldPrediction;
    char resourceDistribution[100];
    char emergencyResponsePlan[100];
} RegionalHub;


Weather* createWeather(float temperature, float rainfall, float windSpeed) {
    Weather* weather = (Weather*)malloc(sizeof(Weather));
    weather->temperature = temperature;
    weather->rainfall = rainfall;
    weather->windSpeed = windSpeed;
    return weather;
}


Crop* createCrop(const char* type, const char* stage, float yield, Weather* weather) {
    Crop* crop = (Crop*)malloc(sizeof(Crop));
    strcpy(crop->cropType, type);
    strcpy(crop->growthStage, stage);
    crop->expectedYield = yield;
    crop->weatherForecast = weather;
    return crop;
}


Equipment* createEquipment(const char* type, const char* status, float fuel, const char* schedule) {
    Equipment* equipment = (Equipment*)malloc(sizeof(Equipment));
    strcpy(equipment->equipmentType, type);
    strcpy(equipment->operationalStatus, status);
    equipment->fuelLevel = fuel;
    strcpy(equipment->activitySchedule, schedule);
    return equipment;
}


Sensor* createSensor(float nutrients, float pH, int pestActivity) {
    Sensor* sensor = (Sensor*)malloc(sizeof(Sensor));
    sensor->soilNutrients = nutrients;
    sensor->pHLevel = pH;
    sensor->pestActivity = pestActivity;
    return sensor;
}


Field* createField(float latitude, float longitude, float soilHealth, float moisture, int numCrops, int numEquipment, int numSensors) {
    Field* field = (Field*)malloc(sizeof(Field));
    field->gpsCoordinates[0] = latitude;
    field->gpsCoordinates[1] = longitude;
    field->soilHealthMetrics = soilHealth;
    field->moistureLevel = moisture;
    field->crops = (Crop*)malloc(numCrops * sizeof(Crop));
    field->numCrops = numCrops;
    field->equipment = (Equipment*)malloc(numEquipment * sizeof(Equipment));
    field->numEquipment = numEquipment;
    field->sensors = (Sensor*)malloc(numSensors * sizeof(Sensor));
    field->numSensors = numSensors;
    return field;
}


RegionalHub* createRegionalHub(int numFields) {
    RegionalHub* hub = (RegionalHub*)malloc(sizeof(RegionalHub));
    hub->fields = (Field*)malloc(numFields * sizeof(Field));
    hub->numFields = numFields;
    hub->aggregateYieldPrediction = 0.0;
    strcpy(hub->resourceDistribution, "Not Set");
    strcpy(hub->emergencyResponsePlan, "Not Set");
    return hub;
}


void freeWeather(Weather* weather) {
    free(weather);
}

void freeCrop(Crop* crop) {
    freeWeather(crop->weatherForecast);
    free(crop);
}

void freeEquipment(Equipment* equipment) {
    free(equipment);
}

void freeSensor(Sensor* sensor) {
    free(sensor);
}

void freeField(Field* field) {
    for (int i = 0; i < field->numCrops; i++) {
        freeCrop(&field->crops[i]);
    }
    for (int i = 0; i < field->numEquipment; i++) {
        freeEquipment(&field->equipment[i]);
    }
    for (int i = 0; i < field->numSensors; i++) {
        freeSensor(&field->sensors[i]);
    }
    free(field->crops);
    free(field->equipment);
    free(field->sensors);
    free(field);
}

void freeRegionalHub(RegionalHub* hub) {
    for (int i = 0; i < hub->numFields; i++) {
        freeField(&hub->fields[i]);
    }
    free(hub->fields);
    free(hub);
}

int main() {
    
    RegionalHub* hub = createRegionalHub(1);
    Field* field = createField(12.34, 56.78, 80.0, 20.0, 2, 2, 2);

    Weather* weather1 = createWeather(30.0, 10.0, 5.0);
    Weather* weather2 = createWeather(28.0, 12.0, 4.0);

    field->crops[0] = *createCrop("Wheat", "Seedling", 1000.0, weather1);
    field->crops[1] = *createCrop("Rice", "Vegetative", 1200.0, weather2);

    field->equipment[0] = *createEquipment("Tractor", "Operational", 50.0, "Scheduled for 10:00 AM");
    field->equipment[1] = *createEquipment("Irrigation System", "Idle", 0.0, "Scheduled for 6:00 PM");

    field->sensors[0] = *createSensor(50.0, 7.5, 1);
    field->sensors[1] = *createSensor(45.0, 6.8, 2);

    hub->fields[0] = *field;

    printf("Field at (%f, %f) has %d crops and %d equipment.\n", field->gpsCoordinates[0], field->gpsCoordinates[1], field->numCrops, field->numEquipment);

    freeRegionalHub(hub);
    return 0;
}
