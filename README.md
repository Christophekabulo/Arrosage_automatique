# Arrosage_automatique 

Les plantes, pour leur survie ont besoin d’un ensemble d’éléments dont l’eau fait partie. Une plante reçoit de l’eau à partir des racines ancrées dans le sol et cette eau provient soit de la pluie soit de l’arrosage effectué par un être humain.

Tout projet fiable d’un chercheur doit avoir un caractère scientifique pour qu’il soit vérifié, accepter, justifier, tester et ensuite le rendre accessible par tout le monde. Notre choix est porté sur un système d’arrosage automatique qui favorisera l’économies en eau, en conditionnant l’arrosage (l’action) à partir de l’humidité du sol (la mesure)

![aaa](https://user-images.githubusercontent.com/95050344/144757629-06d33868-e44f-4447-a8f1-9baab20ec81f.PNG)


N°	MATERIELS UNITAIRE
1	Ordinateur (PC)
2	Arduino UNO
2	Un capteur d’humidité
3	Un transistor
4	Réservoir d’eau 
5	Pompe électrique 12v
6	Une alimentation 12v
7	Résistance et diode
8	Actionnaire 
9	Microcontrôleur

## environnements et outils utilisés

1. papyrus sysml

Papyrus c’est un outil ou un langage de modelisation UML qui sert à modeliser les systèmes aussi complexes qu’ils soient. SysML permet de définir des éléments conceptuels et d’en faire une représentation graphique.

![image](https://user-images.githubusercontent.com/95050344/144758014-65c15f98-52c0-4afe-a756-846addf4b878.png)

2. eclipse

Eclipse un ensemble de sous-projets de développements logiciels, de la fondation Eclipse visant à développer un environnement de production de logiciels libre qui soit extensible, universel et polyvalent, en s'appuyant principalement sur Java. Il nous offre aussi  la possibilité d'émuler des microcontrolleurs et donc de programmer dessus.

![eclipse](https://user-images.githubusercontent.com/95050344/144758994-92735743-bc86-479a-91ce-70c8ad96a1d7.png)


3.proteusà


4. carte STM32F4

La carte STM32F4Discovery permet aux utilisateurs de développer facilement des applications avec un microcontrôleur haute performance STM32F4 muni d’un processeur ARM Cortex-M4 32 bits . . Elle inclut tout ce qui est nécessaire pour les débutants ou pour les utilisateurs expérimentés pour commencer rapidement à effectuer des développements.

![stm32](https://user-images.githubusercontent.com/92784792/144614195-dd010141-afe6-4456-80f0-6390db74f819.PNG)

5. stm32F4CUBE IDE

STM32CubeIDE est un outil de développement multi-OS tout-en-un, qui fait partie de l'écosystème logiciel STM32Cube. C’est aussi une plate-forme de développement C/C++ avancée avec des fonctionnalités de configuration périphérique, de génération de code, de compilation de code et de débogage pour les microcontrôleurs et microprocesseurs STM32.

![image](https://user-images.githubusercontent.com/95050344/144758613-48e94ac5-f8f4-4caa-be88-7365882119c6.png)
 
 6.dht 11

La dihydrotestostérone (DHT) est l'hormone qui possède la plus forte activité androgénique. Elle est produite exclusivement par conversion périphérique de la testostérone sous l'action de la 5-alpha réductase.

La DHT plasmatique augmente dans la plupart des cas d'hyperandrogénie chez la femme, qu'elle soit d'origine ovarienne ou surrénalienne. En outre, certaines formes d'hirsutisme idiopathique sont rattachées à une augmentation de l'activité 5-alpha réductase tissulaire avec conversion accrue de la testostérone en dihydrotestostérone, dont la concentration circulante est augmentée.

### algorigramme


### code MVT

```c
Display_Temp(Temperature);
	  Display_Rh(Humidity);

	  if (Humidity<25 && Temperature>25) {


	 	  /********************** DHT11 *********************/
		  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_0, GPIO_PIN_SET);
		  HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6, GPIO_PIN_RESET);
		  HAL_Delay(500);
	      DHT11_Start();
	 	  Presence = DHT11_Check_Response();
	 	  Rh_byte1 = DHT11_Read ();
	 	  Rh_byte2 = DHT11_Read ();
	 	  Temp_byte1 = DHT11_Read ();
	 	  Temp_byte2 = DHT11_Read ();
	 	  SUM = DHT11_Read();


	 	  TEMP = Temp_byte1;
	 	  RH = Rh_byte1;

	 	  Temperature = (float) TEMP;
	 	  Humidity = (float) RH;

	 	  HAL_Delay (1000);



	      /* USER CODE END WHILE */

	      /* USER CODE BEGIN 3 */
	  	i++;
	  	sprintf(yazi,"%d",i);
	  	lcd_print(1, 1, yazi);
	  	HAL_Delay(30);

	}else{

 	  	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_0, GPIO_PIN_RESET);
 	  	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6, GPIO_PIN_SET);
 	  	HAL_Delay(500);

 	  	i--;
		sprintf(yazi,"%d",i);
		lcd_print(1, 1, yazi);
		HAL_Delay(30);


	}


```
![detecteht](https://user-images.githubusercontent.com/92753979/146954747-8f2c29a8-b25b-44ff-8cd5-0def76ac9177.PNG)


![leadrougesalume](https://user-images.githubusercontent.com/92753979/146954791-e1d8d51c-de85-4736-a101-0df0183d1d1a.PNG)



