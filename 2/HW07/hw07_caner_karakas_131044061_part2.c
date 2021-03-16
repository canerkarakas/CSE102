#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define START_FINISH 2
#define DAY_MONTH_YEAR 3
#define YEAR_HOUR 8776
#define DAY_HOUR 24

typedef enum{
	monday=1, tuesday=2, wednesday=3, thursday=4, friday=5, saturday=6, sunday=0
}day_t;

int calc_years_to_hours(int year){
	return (year-1) * YEAR_HOUR;
}

int calc_days_to_hours(int days){
	return (days-1) * DAY_HOUR;
}

/*dosyadan okunan tarih direk saate cevirip sonra gun sayisi bulunup 7 ile modundan hangi gune denk geldiyse onunla beraber yeni dosyaya yazilmasini saglar*/
void print_text2(FILE *file, FILE *file2){
	char c;
	int dates[10000][3];
	int i=0;
	int year_to_hour;
	int day_to_hour;
	int day;
	while(!feof(file)){
		if(!feof(file)){
			fscanf(file, "%d%c%d%c%d", &dates[i][0], &c, &dates[i][1], &c, &dates[i][2]);
		//	printf("%d %d %d\n", dates[i][0], dates[i][1], dates[i][2]);
			i++;
		}
		else{
			dates[i-1][0] = '\0';
		}
	}
	i=0;
	while(dates[i][0]!='\0'){
		if(dates[i][2]%4==0){
			switch(dates[i][1]){
				case 1:
					year_to_hour = calc_years_to_hours(dates[i][2]);
					day_to_hour = calc_days_to_hours(dates[i][0]);
					day = ((year_to_hour + day_to_hour)/24)%7;
					if(day==monday){
						fprintf(file2, "Monday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==tuesday){
						fprintf(file2, "Tuesday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==wednesday){
						fprintf(file2, "Wednesday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==thursday){
						fprintf(file2, "Thursday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==friday){
						fprintf(file2, "Friday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==saturday){
						fprintf(file2, "Saturday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==sunday){
						fprintf(file2, "Sunday,January %d, %d", dates[i][0], dates[i][2]);
					};break;
				case 2:
					year_to_hour = calc_years_to_hours(dates[i][2]);
					day_to_hour = calc_days_to_hours(dates[i][0]+31);
					day = ((year_to_hour + day_to_hour)/24)%7;
					if(day==monday){
						fprintf(file2, "Monday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==tuesday){
						fprintf(file2, "Tuesday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==wednesday){
						fprintf(file2, "Wednesday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==thursday){
						fprintf(file2, "Thursday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==friday){
						fprintf(file2, "Friday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==saturday){
						fprintf(file2, "Saturday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==sunday){
						fprintf(file2, "Sunday,January %d, %d", dates[i][0], dates[i][2]);
					};break;
				case 3:
					year_to_hour = calc_years_to_hours(dates[i][2]);
					day_to_hour = calc_days_to_hours(dates[i][0]+31+29);
					day = ((year_to_hour + day_to_hour)/24)%7;
					if(day==monday){
						fprintf(file2, "Monday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==tuesday){
						fprintf(file2, "Tuesday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==wednesday){
						fprintf(file2, "Wednesday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==thursday){
						fprintf(file2, "Thursday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==friday){
						fprintf(file2, "Friday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==saturday){
						fprintf(file2, "Saturday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==sunday){
						fprintf(file2, "Sunday,January %d, %d", dates[i][0], dates[i][2]);
					};break;
				case 4:
					year_to_hour = calc_years_to_hours(dates[i][2]);
					day_to_hour = calc_days_to_hours(dates[i][0]+31+29+31);
					day = ((year_to_hour + day_to_hour)/24)%7;
					if(day==monday){
						fprintf(file2, "Monday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==tuesday){
						fprintf(file2, "Tuesday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==wednesday){
						fprintf(file2, "Wednesday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==thursday){
						fprintf(file2, "Thursday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==friday){
						fprintf(file2, "Friday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==saturday){
						fprintf(file2, "Saturday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==sunday){
						fprintf(file2, "Sunday,January %d, %d", dates[i][0], dates[i][2]);
					};break;
				case 5:
					year_to_hour = calc_years_to_hours(dates[i][2]);
					day_to_hour = calc_days_to_hours(dates[i][0]+31+29+31+30);
					day = ((year_to_hour + day_to_hour)/24)%7;
					if(day==monday){
						fprintf(file2, "Monday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==tuesday){
						fprintf(file2, "Tuesday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==wednesday){
						fprintf(file2, "Wednesday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==thursday){
						fprintf(file2, "Thursday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==friday){
						fprintf(file2, "Friday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==saturday){
						fprintf(file2, "Saturday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==sunday){
						fprintf(file2, "Sunday,January %d, %d", dates[i][0], dates[i][2]);
					};break;
				case 6:
					year_to_hour = calc_years_to_hours(dates[i][2]);
					day_to_hour = calc_days_to_hours(dates[i][0]+31+29+31+30+31);
					day = ((year_to_hour + day_to_hour)/24)%7;
					if(day==monday){
						fprintf(file2, "Monday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==tuesday){
						fprintf(file2, "Tuesday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==wednesday){
						fprintf(file2, "Wednesday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==thursday){
						fprintf(file2, "Thursday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==friday){
						fprintf(file2, "Friday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==saturday){
						fprintf(file2, "Saturday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==sunday){
						fprintf(file2, "Sunday,January %d, %d", dates[i][0], dates[i][2]);
					};break;
				case 7:
					year_to_hour = calc_years_to_hours(dates[i][2]);
					day_to_hour = calc_days_to_hours(dates[i][0]+31+29+31+30+31+30);
					day = ((year_to_hour + day_to_hour)/24)%7;
					if(day==monday){
						fprintf(file2, "Monday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==tuesday){
						fprintf(file2, "Tuesday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==wednesday){
						fprintf(file2, "Wednesday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==thursday){
						fprintf(file2, "Thursday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==friday){
						fprintf(file2, "Friday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==saturday){
						fprintf(file2, "Saturday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==sunday){
						fprintf(file2, "Sunday,January %d, %d", dates[i][0], dates[i][2]);
					};break;
				case 8:
					year_to_hour = calc_years_to_hours(dates[i][2]);
					day_to_hour = calc_days_to_hours(dates[i][0]+31+29+31+30+31+30+31);
					day = ((year_to_hour + day_to_hour)/24)%7;
					if(day==monday){
						fprintf(file2, "Monday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==tuesday){
						fprintf(file2, "Tuesday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==wednesday){
						fprintf(file2, "Wednesday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==thursday){
						fprintf(file2, "Thursday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==friday){
						fprintf(file2, "Friday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==saturday){
						fprintf(file2, "Saturday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==sunday){
						fprintf(file2, "Sunday,January %d, %d", dates[i][0], dates[i][2]);
					};break;
				case 9:
					year_to_hour = calc_years_to_hours(dates[i][2]);
					day_to_hour = calc_days_to_hours(dates[i][0]+31+29+31+30+31+30+31+31);
					day = ((year_to_hour + day_to_hour)/24)%7;
					if(day==monday){
						fprintf(file2, "Monday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==tuesday){
						fprintf(file2, "Tuesday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==wednesday){
						fprintf(file2, "Wednesday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==thursday){
						fprintf(file2, "Thursday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==friday){
						fprintf(file2, "Friday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==saturday){
						fprintf(file2, "Saturday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==sunday){
						fprintf(file2, "Sunday,January %d, %d", dates[i][0], dates[i][2]);
					};break;
				case 10:
					year_to_hour = calc_years_to_hours(dates[i][2]);
					day_to_hour = calc_days_to_hours(dates[i][0]+31+29+31+30+31+30+31+31+30);
					day = ((year_to_hour + day_to_hour)/24)%7;
					if(day==monday){
						fprintf(file2, "Monday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==tuesday){
						fprintf(file2, "Tuesday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==wednesday){
						fprintf(file2, "Wednesday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==thursday){
						fprintf(file2, "Thursday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==friday){
						fprintf(file2, "Friday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==saturday){
						fprintf(file2, "Saturday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==sunday){
						fprintf(file2, "Sunday,January %d, %d", dates[i][0], dates[i][2]);
					};break;
				case 11:
					year_to_hour = calc_years_to_hours(dates[i][2]);
					day_to_hour = calc_days_to_hours(dates[i][0]+31+29+31+30+31+30+31+31+30+31);
					day = ((year_to_hour + day_to_hour)/24)%7;
					if(day==monday){
						fprintf(file2, "Monday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==tuesday){
						fprintf(file2, "Tuesday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==wednesday){
						fprintf(file2, "Wednesday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==thursday){
						fprintf(file2, "Thursday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==friday){
						fprintf(file2, "Friday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==saturday){
						fprintf(file2, "Saturday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==sunday){
						fprintf(file2, "Sunday,January %d, %d", dates[i][0], dates[i][2]);
					};break;
				case 12:
					year_to_hour = calc_years_to_hours(dates[i][2]);
					day_to_hour = calc_days_to_hours(dates[i][0]+31+29+31+30+31+30+31+31+30+31+30);
					day = ((year_to_hour + day_to_hour)/24)%7;
					if(day==monday){
						fprintf(file2, "Monday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==tuesday){
						fprintf(file2, "Tuesday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==wednesday){
						fprintf(file2, "Wednesday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==thursday){
						fprintf(file2, "Thursday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==friday){
						fprintf(file2, "Friday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==saturday){
						fprintf(file2, "Saturday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==sunday){
						fprintf(file2, "Sunday,January %d, %d", dates[i][0], dates[i][2]);
					};break;
			}
			fprintf(file2, "\n");
		}
		if(dates[i][2]%4!=0){
			switch(dates[i][1]){
				case 1:
					year_to_hour = calc_years_to_hours(dates[i][2]);
					day_to_hour = calc_days_to_hours(dates[i][0]);
					day = ((year_to_hour + day_to_hour)/24)%7;
					if(day==monday){
						fprintf(file2, "Monday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==tuesday){
						fprintf(file2, "Tuesday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==wednesday){
						fprintf(file2, "Wednesday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==thursday){
						fprintf(file2, "Thursday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==friday){
						fprintf(file2, "Friday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==saturday){
						fprintf(file2, "Saturday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==sunday){
						fprintf(file2, "Sunday,January %d, %d", dates[i][0], dates[i][2]);
					};break;
				case 2:
					year_to_hour = calc_years_to_hours(dates[i][2]);
					day_to_hour = calc_days_to_hours(dates[i][0]+31);
					day = ((year_to_hour + day_to_hour)/24)%7;
					if(day==monday){
						fprintf(file2, "Monday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==tuesday){
						fprintf(file2, "Tuesday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==wednesday){
						fprintf(file2, "Wednesday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==thursday){
						fprintf(file2, "Thursday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==friday){
						fprintf(file2, "Friday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==saturday){
						fprintf(file2, "Saturday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==sunday){
						fprintf(file2, "Sunday,January %d, %d", dates[i][0], dates[i][2]);
					};break;
				case 3:
					year_to_hour = calc_years_to_hours(dates[i][2]);
					day_to_hour = calc_days_to_hours(dates[i][0]+31+28);
					day = ((year_to_hour + day_to_hour)/24)%7;
					if(day==monday){
						fprintf(file2, "Monday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==tuesday){
						fprintf(file2, "Tuesday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==wednesday){
						fprintf(file2, "Wednesday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==thursday){
						fprintf(file2, "Thursday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==friday){
						fprintf(file2, "Friday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==saturday){
						fprintf(file2, "Saturday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==sunday){
						fprintf(file2, "Sunday,January %d, %d", dates[i][0], dates[i][2]);
					};break;
				case 4:
					year_to_hour = calc_years_to_hours(dates[i][2]);
					day_to_hour = calc_days_to_hours(dates[i][0]+31+28+31);
					day = ((year_to_hour + day_to_hour)/24)%7;
					if(day==monday){
						fprintf(file2, "Monday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==tuesday){
						fprintf(file2, "Tuesday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==wednesday){
						fprintf(file2, "Wednesday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==thursday){
						fprintf(file2, "Thursday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==friday){
						fprintf(file2, "Friday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==saturday){
						fprintf(file2, "Saturday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==sunday){
						fprintf(file2, "Sunday,January %d, %d", dates[i][0], dates[i][2]);
					};break;
				case 5:
					year_to_hour = calc_years_to_hours(dates[i][2]);
					day_to_hour = calc_days_to_hours(dates[i][0]+31+28+31+30);
					day = ((year_to_hour + day_to_hour)/24)%7;
					if(day==monday){
						fprintf(file2, "Monday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==tuesday){
						fprintf(file2, "Tuesday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==wednesday){
						fprintf(file2, "Wednesday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==thursday){
						fprintf(file2, "Thursday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==friday){
						fprintf(file2, "Friday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==saturday){
						fprintf(file2, "Saturday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==sunday){
						fprintf(file2, "Sunday,January %d, %d", dates[i][0], dates[i][2]);
					};break;
				case 6:
					year_to_hour = calc_years_to_hours(dates[i][2]);
					day_to_hour = calc_days_to_hours(dates[i][0]+31+28+31+30+31);
					day = ((year_to_hour + day_to_hour)/24)%7;
					if(day==monday){
						fprintf(file2, "Monday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==tuesday){
						fprintf(file2, "Tuesday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==wednesday){
						fprintf(file2, "Wednesday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==thursday){
						fprintf(file2, "Thursday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==friday){
						fprintf(file2, "Friday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==saturday){
						fprintf(file2, "Saturday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==sunday){
						fprintf(file2, "Sunday,January %d, %d", dates[i][0], dates[i][2]);
					};break;
				case 7:
					year_to_hour = calc_years_to_hours(dates[i][2]);
					day_to_hour = calc_days_to_hours(dates[i][0]+31+28+31+30+31+30);
					day = ((year_to_hour + day_to_hour)/24)%7;
					if(day==monday){
						fprintf(file2, "Monday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==tuesday){
						fprintf(file2, "Tuesday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==wednesday){
						fprintf(file2, "Wednesday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==thursday){
						fprintf(file2, "Thursday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==friday){
						fprintf(file2, "Friday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==saturday){
						fprintf(file2, "Saturday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==sunday){
						fprintf(file2, "Sunday,January %d, %d", dates[i][0], dates[i][2]);
					};break;
				case 8:
					year_to_hour = calc_years_to_hours(dates[i][2]);
					day_to_hour = calc_days_to_hours(dates[i][0]+31+28+31+30+31+30+31);
					day = ((year_to_hour + day_to_hour)/24)%7;
					if(day==monday){
						fprintf(file2, "Monday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==tuesday){
						fprintf(file2, "Tuesday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==wednesday){
						fprintf(file2, "Wednesday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==thursday){
						fprintf(file2, "Thursday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==friday){
						fprintf(file2, "Friday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==saturday){
						fprintf(file2, "Saturday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==sunday){
						fprintf(file2, "Sunday,January %d, %d", dates[i][0], dates[i][2]);
					};break;
				case 9:
					year_to_hour = calc_years_to_hours(dates[i][2]);
					day_to_hour = calc_days_to_hours(dates[i][0]+31+28+31+30+31+30+31+31);
					day = ((year_to_hour + day_to_hour)/24)%7;
					if(day==monday){
						fprintf(file2, "Monday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==tuesday){
						fprintf(file2, "Tuesday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==wednesday){
						fprintf(file2, "Wednesday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==thursday){
						fprintf(file2, "Thursday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==friday){
						fprintf(file2, "Friday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==saturday){
						fprintf(file2, "Saturday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==sunday){
						fprintf(file2, "Sunday,January %d, %d", dates[i][0], dates[i][2]);
					};break;
				case 10:
					year_to_hour = calc_years_to_hours(dates[i][2]);
					day_to_hour = calc_days_to_hours(dates[i][0]+31+28+31+30+31+30+31+31+30);
					day = ((year_to_hour + day_to_hour)/24)%7;
					if(day==monday){
						fprintf(file2, "Monday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==tuesday){
						fprintf(file2, "Tuesday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==wednesday){
						fprintf(file2, "Wednesday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==thursday){
						fprintf(file2, "Thursday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==friday){
						fprintf(file2, "Friday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==saturday){
						fprintf(file2, "Saturday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==sunday){
						fprintf(file2, "Sunday,January %d, %d", dates[i][0], dates[i][2]);
					};break;
				case 11:
					year_to_hour = calc_years_to_hours(dates[i][2]);
					day_to_hour = calc_days_to_hours(dates[i][0]+31+28+31+30+31+30+31+31+30+31);
					day = ((year_to_hour + day_to_hour)/24)%7;
					if(day==monday){
						fprintf(file2, "Monday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==tuesday){
						fprintf(file2, "Tuesday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==wednesday){
						fprintf(file2, "Wednesday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==thursday){
						fprintf(file2, "Thursday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==friday){
						fprintf(file2, "Friday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==saturday){
						fprintf(file2, "Saturday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==sunday){
						fprintf(file2, "Sunday,January %d, %d", dates[i][0], dates[i][2]);
					};break;
				case 12:
					year_to_hour = calc_years_to_hours(dates[i][2]);
					day_to_hour = calc_days_to_hours(dates[i][0]+31+28+31+30+31+30+31+31+30+31+30);
					day = ((year_to_hour + day_to_hour)/24)%7;
					if(day==monday){
						fprintf(file2, "Monday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==tuesday){
						fprintf(file2, "Tuesday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==wednesday){
						fprintf(file2, "Wednesday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==thursday){
						fprintf(file2, "Thursday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==friday){
						fprintf(file2, "Friday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==saturday){
						fprintf(file2, "Saturday,January %d, %d", dates[i][0], dates[i][2]);
					}
					if(day==sunday){
						fprintf(file2, "Sunday,January %d, %d", dates[i][0], dates[i][2]);
					};break;
			}
			fprintf(file2, "\n");
		}
		i++;
	}
}

void print_text(FILE *file, int date[START_FINISH][DAY_MONTH_YEAR], int dates[][DAY_MONTH_YEAR]){/*dates olarak kullandigim array 2. fonksiyon icin lazim olur diye almistim ama sonra dosyadan okuyarak yapilacagini gordum. bu sekilde de tutup diger dosyaya yazabilirdik diye kaldirmadim*/
	int temp_day,temp_month,temp_year;
	int control=0;
	int i=0, j=0;
	while(control==0){
		fprintf(file, "%d", date[0][0]);
		temp_day = date[0][0];
		dates[i][j] = temp_day;
	//	printf("%d-", dates[i][j]);
		j++;
		fprintf(file, "/");
		fprintf(file, "%d", date[0][1]);
		temp_month = date[0][1];
		dates[i][j] = temp_month;
	//	printf("%d-", dates[i][j]);
		j++;
		fprintf(file, "/");
		fprintf(file, "%d", date[0][2]);
		temp_year = date[0][2];
		dates[i][j] = temp_year;
	//	printf("%d\n", dates[i][j]);
		i++;
		j=0;
		fprintf(file, "\n");
		if(date[0][2]!=date[1][2]){
			temp_day = date[0][0];
			temp_month = date[0][1];
			temp_year = date[0][2];
			switch(date[0][1]){
				case 1:
					if(temp_day<31){
						temp_day++;
						date[0][0] = temp_day;
						print_text(file, date, dates);
					}
					else{
						temp_day = 1;
						date[0][0] = temp_day;
						temp_month++;
						date[0][1] = temp_month;
						print_text(file, date, dates);
					};break;
				case 2:
					if(temp_year%4==0){
						if(temp_day<29){
							temp_day++;
							date[0][0] = temp_day;
							print_text(file, date, dates);
						}
						else{
							temp_day = 1;
							date[0][0] = temp_day;
							temp_month++;
							date[0][1] = temp_month;
							print_text(file, date, dates);
						}
					}
					else{
						if(temp_day<28){
							temp_day++;
							date[0][0] = temp_day;
							print_text(file, date, dates);
						}
						else{
							temp_day = 1;
							date[0][0] = temp_day;
							temp_month++;
							date[0][1] = temp_month;
							print_text(file, date, dates);
						}
					};break;
				case 3:
					if(temp_day<31){
						temp_day++;
						date[0][0] = temp_day;
						print_text(file, date, dates);
					}
					else{
						temp_day = 1;
						date[0][0] = temp_day;
						temp_month++;
						date[0][1] = temp_month;
						print_text(file, date, dates);
					};break;
				case 4:
					if(temp_day<30){
						temp_day++;
						date[0][0] = temp_day;
						print_text(file, date, dates);
					}
					else{
						temp_day = 1;
						date[0][0] = temp_day;
						temp_month++;
						date[0][1] = temp_month;
						print_text(file, date, dates);
					};break;
				case 5:
					if(temp_day<31){
						temp_day++;
						date[0][0] = temp_day;
						print_text(file, date, dates);
					}
					else{
						temp_day = 1;
						date[0][0] = temp_day;
						temp_month++;
						date[0][1] = temp_month;
						print_text(file, date, dates);
					};break;
				case 6:
					if(temp_day<30){
						temp_day++;
						date[0][0] = temp_day;
						print_text(file, date, dates);
					}
					else{
						temp_day = 1;
						date[0][0] = temp_day;
						temp_month++;
						date[0][1] = temp_month;
						print_text(file, date, dates);
					};break;
				case 7:
					if(temp_day<31){
						temp_day++;
						date[0][0] = temp_day;
						print_text(file, date, dates);
					}
					else{
						temp_day = 1;
						date[0][0] = temp_day;
						temp_month++;
						date[0][1] = temp_month;
						print_text(file, date, dates);
					};break;
				case 8:
					if(temp_day<31){
						temp_day++;
						date[0][0] = temp_day;
						print_text(file, date, dates);
					}
					else{
						temp_day = 1;
						date[0][0] = temp_day;
						temp_month++;
						date[0][1] = temp_month;
						print_text(file, date, dates);
					};break;
				case 9:
					if(temp_day<30){
						temp_day++;
						date[0][0] = temp_day;
						print_text(file, date, dates);
					}
					else{
						temp_day = 1;
						date[0][0] = temp_day;
						temp_month++;
						date[0][1] = temp_month;
						print_text(file, date, dates);
					};break;
				case 10:
					if(temp_day<31){
						temp_day++;
						date[0][0] = temp_day;
						print_text(file, date, dates);
					}
					else{
						temp_day = 1;
						date[0][0] = temp_day;
						temp_month++;
						date[0][1] = temp_month;
						print_text(file, date, dates);
					};break;
				case 11:
					if(temp_day<30){
						temp_day++;
						date[0][0] = temp_day;
						print_text(file, date, dates);
					}
					else{
						temp_day = 1;
						date[0][0] = temp_day;
						temp_month++;
						date[0][1] = temp_month;
						print_text(file, date, dates);
					};break;
				case 12:
					if(temp_day<31){
						temp_day++;
						date[0][0] = temp_day;
						print_text(file, date, dates);
					}
					else{
						temp_day = 1;
						date[0][0] = temp_day;
						temp_month = 1;
						date[0][1] = temp_month;
						temp_year++;
						date[0][2] = temp_year;
						print_text(file, date, dates);
					};break;
				default:;break;
			}
		}
		else{
			temp_day = date[0][0];
			temp_month = date[0][1];
			temp_year = date[0][2];
			if(date[0][1]<date[1][1]){
				switch(date[0][1]){
					case 1:
						if(temp_day<31){
							temp_day++;
							date[0][0] = temp_day;
							print_text(file, date, dates);
						}
						else{
							temp_day = 1;
							date[0][0] = temp_day;
							temp_month++;
							date[0][1] = temp_month;
							print_text(file, date, dates);
						};break;
					case 2:
						if(temp_year%4==0){
							if(temp_day<29){
								temp_day++;
								date[0][0] = temp_day;
								print_text(file, date, dates);
							}
							else{
								temp_day = 1;
								date[0][0] = temp_day;
								temp_month++;
								date[0][1] = temp_month;
								print_text(file, date, dates);
							}
						}
						else{
							if(temp_day<28){
								temp_day++;
								date[0][0] = temp_day;
								print_text(file, date, dates);
							}
							else{
								temp_day = 1;
								date[0][0] = temp_day;
								temp_month++;
								date[0][1] = temp_month;
								print_text(file, date, dates);
							}
						};break;
					case 3:
						if(temp_day<31){
							temp_day++;
							date[0][0] = temp_day;
							print_text(file, date, dates);
						}
						else{
							temp_day = 1;
							date[0][0] = temp_day;
							temp_month++;
							date[0][1] = temp_month;
							print_text(file, date, dates);
						};break;
					case 4:
						if(temp_day<30){
							temp_day++;
							date[0][0] = temp_day;
							print_text(file, date, dates);
						}
						else{
							temp_day = 1;
							date[0][0] = temp_day;
							temp_month++;
							date[0][1] = temp_month;
							print_text(file, date, dates);
						};break;
					case 5:
						if(temp_day<31){
							temp_day++;
							date[0][0] = temp_day;
							print_text(file, date, dates);
						}
						else{
							temp_day = 1;
							date[0][0] = temp_day;
							temp_month++;
							date[0][1] = temp_month;
							print_text(file, date, dates);
						};break;
					case 6:
						if(temp_day<30){
							temp_day++;
							date[0][0] = temp_day;
							print_text(file, date, dates);
						}
						else{
							temp_day = 1;
							date[0][0] = temp_day;
							temp_month++;
							date[0][1] = temp_month;
							print_text(file, date, dates);
						};break;
					case 7:
						if(temp_day<31){
							temp_day++;
							date[0][0] = temp_day;
							print_text(file, date, dates);
						}
						else{
							temp_day = 1;
							date[0][0] = temp_day;
							temp_month++;
							date[0][1] = temp_month;
							print_text(file, date, dates);
						};break;
					case 8:
						if(temp_day<31){
							temp_day++;
							date[0][0] = temp_day;
							print_text(file, date, dates);
						}
						else{
							temp_day = 1;
							date[0][0] = temp_day;
							temp_month++;
							date[0][1] = temp_month;
							print_text(file, date, dates);
						};break;
					case 9:
						if(temp_day<30){
							temp_day++;
							date[0][0] = temp_day;
							print_text(file, date, dates);
						}
						else{
							temp_day = 1;
							date[0][0] = temp_day;
							temp_month++;
							date[0][1] = temp_month;
							print_text(file, date, dates);
						};break;
					case 10:
							if(temp_day<31){
							temp_day++;
							date[0][0] = temp_day;
							print_text(file, date, dates);
						}
						else{
							temp_day = 1;
							date[0][0] = temp_day;
							temp_month++;
							date[0][1] = temp_month;
							print_text(file, date, dates);
						};break;
					case 11:
						if(temp_day<30){
							temp_day++;
							date[0][0] = temp_day;
							print_text(file, date, dates);
						}
						else{
							temp_day = 1;
							date[0][0] = temp_day;
							temp_month++;
							date[0][1] = temp_month;
							print_text(file, date, dates);
						};break;
					case 12:
						if(temp_day<31){
							temp_day++;
							date[0][0] = temp_day;
							print_text(file, date, dates);
						}
						else{
							temp_day = 1;
							date[0][0] = temp_day;
							temp_month = 1;
							date[0][1] = temp_month;
							temp_year++;
							date[0][2] = temp_year;
							print_text(file, date, dates);
						};break;
					default:;break;
				}
			}
			if(date[0][1]==date[1][1]){
				if(date[0][0]<date[1][0]){
					temp_day++;
					date[0][0] = temp_day;
					print_text(file, date, dates);
				}
				else{
					fclose(file);
					control = 1;
				}
			}
		}
	}
	dates[i][j]='\0';
}

int main(void){
	FILE *file, *file2;
	file = fopen("input_date.txt", "w");
	
	printf("Enter a start-date(dd/MM/yyyy): ");
	int date[START_FINISH][DAY_MONTH_YEAR] = { { 0,0,0 }, { 0,0,0 } };
	int dates[1000][DAY_MONTH_YEAR];
	char ch;
	for(int i=0;i<3;i++){
		scanf("%d", &date[0][i]);
		scanf("%c", &ch);
	}
	printf("Enter a finish-date(dd/MM/yyyy): ");
	for(int i=0;i<3;i++){
		scanf("%d", &date[1][i]);
		scanf("%c", &ch);
	}
	if(date[0][2]>date[1][2]){
		printf("error1");
	}
	if(date[0][0]>31 || date[1][0]>31){
		printf("error2");
	}
	else{
		if(date[0][2]==date[1][2]){
			if(date[0][1]>date[1][1]){
				printf("error3");
			}
			else{
				if(date[0][1]==date[1][1]){
					if(date[0][0]>date[1][0]){
						printf("error4");
					}
					else{
						print_text(file, date, dates);
					}
				}
				else{
					print_text(file, date, dates);
				}
			}
		}
		else{
			print_text(file, date, dates);
		}
	}
	fclose(file);
	
	file = fopen("input_date.txt", "r");
	file2 = fopen("new_date.txt", "w");
	
	print_text2(file, file2);
	fclose(file);
	fclose(file2);
	return 0;
}
