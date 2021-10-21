//Read data from DHT11 once
//temp: temperature value (range: 0 ~ 50 °)
//humi: humidity value (range: 20% ~ 90%)
//Return value: 0, normal; 1. Reading failed
unsigned char DHT11_Read_Data(unsigned char *temp,unsigned char *humi)
{
 	unsigned char buf[5];
	unsigned char i;
	DHT11_Rst();
	if(DHT11_Check()==0)
	{
		//HAL_GPIO_WritePin(GPIOA,GPIO_PIN_1,GPIO_PIN_RESET);
		for(i=0;i<5;i++)//Read 40 bit data
		{
			buf[i]=DHT11_Read_Byte();
		}
		if((buf[0]+buf[1]+buf[2]+buf[3])==buf[4])
		{
			*humi=buf[0];
			*temp=buf[2];
		}
	}else return 1;
	return 0;
}
