#include <iostream>
using namespace std;

void setPotion(int count, int* p_HPPotion, int* p_MPPotion) {
    *p_HPPotion = count;
    *p_MPPotion = count;
}
void addPotion(int count, int* p_HPPotion, int* p_MPPotion) {
    *p_HPPotion += count;
    *p_MPPotion += count;
}

int main() {
    int status[7] = { 0 };
    // 0: HP, 1: MP, 2: 공격력, 3: 방어력, 4: 나의 레벨, 5: 힘, 6: 지능

    while (1) {
        cout << "HP와 MP를 입력해주세요: ";
        cin >> status[0] >> status[1];

        if (status[0] > 50 && status[1] > 50) {
            break;
        }
        cout << "HP와 MP의 값이 너무 작습니다. 다시 입력해주세요." << endl;
    }

    while (1) {
        cout << "공격력과 방어력을 입력해주세요: ";
        cin >> status[2] >> status[3];

        if (status[2] > 0 || status[3] > 0) {
            break;
        }
        cout << "공격력과 방어력의 값이 너무 작습니다. 다시 입력해주세요." << endl;
    }

    int num;
    int HP_P = 0;
    int MP_P = 0;
    setPotion(5, &HP_P, &MP_P);
    int Level = 0;
    cout << "* 포션이 지급되었습니다. (HP, MP 포션 각 5개)" << endl;
    cout << "=============================================" << endl;

    cout << "<스탯 관리 시스템>" << endl;
    cout << "1. HP UP\n2. MP UP\n3. 공격력 UP\n4. 방어력 UP\n5. 현재 능력치\n6. Level UP\n0. 나가기" << endl;
    while (1) {
        cout << "번호를 선택해주세요: ";
        cin >> num;

        switch (num) {
            case 1:
                if (HP_P <= 0) {
                    cout << "포션이 부족합니다." << endl;
                    continue;
                }
                status[0] += 20;
                HP_P -= 1;
                cout << "* HP가 20 증가되었습니다. 포션이 1개 차감됩니다." << endl;
                cout << "현재 HP: " << status[0] << endl;
                cout << "남은 포션 수: " << HP_P << endl;
                break;
            case 2:
                if (MP_P <= 0) {
                    cout << "포션이 부족합니다." << endl;
                    continue;
                }
                status[1] += 20;
                MP_P -= 1;
                cout << "* MP가 20 증가되었습니다. 포션이 1개 차감됩니다." << endl;
                cout << "현재 MP: " << status[1] << endl;
                cout << "남은 포션 수: " << MP_P << endl;
                break;
            case 3:
                status[2] *= 2;
                cout << "* 공격력이 2배로 증가되었습니다." << endl;
                cout << "현재 공격력: " << status[2] << endl;
                break;
            case 4:
                status[3] *= 2;
                cout << "* 방어력이 2배로 증가되었습니다." << endl;
                cout << "현재 방어력: " << status[3] << endl;
                break;
            case 5:
                cout << "* HP : " << status[0] << ", MP : " << status[1] << ", 공격력 : " << status[2] << ", 방어력 : " << status[3] << ", 나의 레벨 : " << status[4] << endl;
                cout << "힘 : " << status[5] << ", 지능 : " << status[6] << endl;
                cout << "남은 HP/MP 포션 수 : " << HP_P << "/" << MP_P << endl;
                break;
            case 6:
                cout << "* 레벨업! HP/MP 포션이 지급됩니다." << endl;
                Level += 1;
                if (Level == 6) {
                    status[4] += 1;
                    status[5] += 10;
                    status[6] += 5;
                    cout << "축하합니다! 힘 10, 지능 5가 증가되었습니다." << endl;
                    Level = 0;
                }
                addPotion(1, &HP_P, &MP_P);

                cout << "남은 HP/MP 포션 수 : " << HP_P << "/" << MP_P << endl;
                break;
            case 0:
                cout << "프로그램을 종료합니다.";
                break;
            default:
                cout << "올바르지 않은 값입니다. 다시 입력해주세요." << endl;
                break;
        }
        if (num == 0) {
            break;
        }
    }
    return 0;
}
