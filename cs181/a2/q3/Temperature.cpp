class Temperature
{
private:
    static const int ETHYL_FREEZING_POINT = -173;
    static const int ETHYL_BOILING_POINT = 172;
    static const int OXYGEN_FREEZING_POINT = -362;
    static const int OXYGEN_BOILING_POINT = -302;
    static const int WATER_FREEZING_POINT = 32;
    static const int WATER_BOILING_POINT = 212;
    int temperature;

public:
    // default constructor
    Temperature()
    {
	this->temperature = 0;
    }

    // argument constructor
    // parameter: temperature - the temperature to be initialized 
    Temperature(int temperature)
    {
	this->temperature = temperature;
    }
    
    // accessor for temperature
    // return: the current temperature
    int getTemperature() const
    {
	return this->temperature;
    }

    // mutator for temperature
    // parameter: temperature - the new temperature to set
    void setTemperature(int temperature)
    {
	this->temperature = temperature;
    }
    
    // checks if ethyl will freeze at the stored temperature
    // return: true if ethyl will freeze, false if it won't
    bool isEthylFreezing() const
    {
	return this->temperature <= ETHYL_FREEZING_POINT;
    }

    // checks if ethyl will boil at the stored temperature
    // return: true if ethyl will boil, false if it won't
    bool isEthylBoiling() const
    {
	return this->temperature >= ETHYL_BOILING_POINT;
    }

    // checks if oxygen will freeze at the stored temperature
    // return: true if oxygen will freeze, false if it won't
    bool isOxygenFreezing() const
    {
	return this->temperature <= OXYGEN_FREEZING_POINT;
    }

    // checks if oxygen will boil at the stored temperature
    // return: true if oxygen will boil, false if it won't
    bool isOxygenBoiling() const
    {
	return this->temperature >= OXYGEN_BOILING_POINT;
    }
    
    // checks if water will freeze at the stored temperature
    // return: true if water will freeze, false if it won't
    bool isWaterFreezing() const
    {
	return this->temperature <= WATER_FREEZING_POINT;
    }

    // checks if water will boil at the stored temperature
    // return: true if water will boil, false if it won't
    bool isWaterBoiling() const
    {
	return this->temperature >= WATER_BOILING_POINT;
    }
};
