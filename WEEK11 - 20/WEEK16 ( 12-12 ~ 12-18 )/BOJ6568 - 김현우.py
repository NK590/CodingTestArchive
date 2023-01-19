import sys

input = sys.stdin.readline

# 폰 노이만 구조 : 메모리에 실행 코드와 데이터가 구분되지 않고 같이 올라가는 구조

mem_size = 1 << 5       # 메모리 사이즈 : 32바이트 -> 총 인덱스 32개
adder_max_val = 1 << 8  # 가산기 사이즈 : 8비트

while True:
    memory = [0 for _ in range(mem_size)] # 컴퓨터의 메모리
    adder = 0 # 가산기
    pc = 0 # 프로그램 카운터 (포인터)

    # 먼저 메모리에 프로그램 입력받아 올리기
    for i in range(mem_size):
        try:
            memory[i] = int(input().rstrip(), 2)
        except:
            exit()

    # 메모리 주소에 따라 순차적으로 프로그램 실행
    while True:
        adr = memory[pc] # 메모리의 해당 주소에 올라가 있는 실제 값
        cmd = adr // mem_size # 명령어 앞 3비트
        val = adr % mem_size # 명령어 뒤 5비트
        pc = (pc + 1) % mem_size # 메모리 주소를 나타내는 프로그램 카운터

        if cmd == 0:
            memory[val] = adder
        elif cmd == 1:
            adder = memory[val]
        elif cmd == 2:
            if adder == 0:
                pc = val
        elif cmd == 3:
            pass
        elif cmd == 4:
            adder = (adder - 1) % adder_max_val
        elif cmd == 5:
            adder = (adder + 1) % adder_max_val
        elif cmd == 6:
            pc = val
        elif cmd == 7:
            break
    
    # 프로그램 종료 후 가산기 값을 2진수로 바꿔 출력
    print(bin(adder)[2:].zfill(8))