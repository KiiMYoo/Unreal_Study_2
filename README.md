# 프로젝트 소개
C++ 코드를 통해 움직이는 액터 생성하고 플랫포머 게임 레벨 디자인 하기

## 구현 액터 목록

1. 회전 액터: 지속적으로 회전하는 액터 / 헬리콥터 프로펠러를 표현하기 위해 사용

2. 제한 회전 액터: 일정 각도 회전 후 정지하는 액터 / 무너지는 건물을 표현하기 위해 사용

3. 왕복 이동 액터: 지속적으로 일정 거리만큼 왕복 이동하는 액터 / 움직이는 땅 플랫폼을 표현하기 위해 사용

4. 일방향 이동 액터: 일정 거리 이동 후 정지하는 액터 / 차오르는 물 표현하기 위해 사용

5. 액터 스포너: 특정 액터 스폰 시키는 액터 / 자동차 스폰을 위해 사용

6. 스폰용 액터: 액터 스포너로 스폰 시킬 액터 / 랜덤 속도로 이동하는 자동차 표현하기 위해 사용

## 레벨 디자인

### 개요

- 자연 재해(지진)을 배경으로 한 플랫포머 게임 제작
- 플레이 영상 유튜브 링크
https://youtu.be/wgAh1iREOIk?si=HoF-0JpnbnrZrowE

### 구간 설명

0. 시작점
  - 무너지는 건물 연출
    -> 배경 인식 & 목표 제공
    
1. 점프 탈출
  - 지진으로 인해 갈라지고 흔들리는 땅 탈출
  - 갈라진 땅 사이 수도관 통해 이동 -> 다음 구간 힌트
    
2. 퍼즐 & 점프 탈출
  - 헬리콥터 프로펠러 피하기 위해 공간 파악
  - 수도관 활용 or 헬리콥터 꼬리 틈으로 이동
    
3. 타임어택
  - 수도관 누수로 인해 차오르는 물 탈출
  - 0 구간에서 연출로 활용한 무너지는 건물 장애물로 활용
  - 하강을 통한 플레이어 밀기 -> 공간 제한으로 탈출 필요성 인식
  - 재하강 -> 재하강 구간을 두어 긴장감 강조
    
4. 충돌체 피하기
  - 랜덤하게 나오는 자동차 피하기
  - 플레이어 밀기 -> 공간 전환을 위함
  - 속도 & 스폰 위치 랜덤하게 설정해 긴장감 강조
