/*
The game is simple. You initially have ‘H’ amount of health and ‘A’ amount of armor. At any instant you can live
in any of the three places - fire, water and air. After every unit time, you have to change your place of living. 
For example if you are currently living at fire, you can either step into water or air.

If you step into air, your health increases by 3 and your armor increases by 2

If you step into water, your health decreases by 5 and your armor decreases by 10

If you step into fire, your health decreases by 20 and your armor increases by 5

If your health or armor becomes <=0, you will die instantly

Find the maximum time you can survive.
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int h,a;
		cin >> h >> a;
		int time = 1;
		bool was_last_air = true;
		h += 3;
		a += 2;
		while(1){
			if(was_last_air == false){
				h += 3;
				a += 2;
				time++;
				was_last_air = true;
			}
			else if(h > 5 && a > 10){
				h -= 5;
				a -= 10;
				time++;
				was_last_air = false;
			}
			else if(h > 20){
				h -= 20;
				a += 5;
				time++;
				was_last_air = false;
			}
			else break;
		}
		cout << time << endl;
	}
	return 0;
}