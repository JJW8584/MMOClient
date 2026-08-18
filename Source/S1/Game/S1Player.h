// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "Protocol.pb.h"
#include "S1Player.generated.h"

UCLASS()
class S1_API AS1Player : public ACharacter
{
	GENERATED_BODY()

public:
	AS1Player();
	~AS1Player();

protected:
	virtual void BeginPlay();
	virtual void Tick(float DeltaSeconds) override;

public:
	bool IsMyPlayer();

	Protocol::MoveState GetMoveState() { return PlayerInfo->state(); }
	void SetMoveState(Protocol::MoveState State);

public:
	void SetMoveInfo(const Protocol::MoveInfo& Info);
	void SetDestInfo(const Protocol::MoveInfo& Info);
	Protocol::MoveInfo* GetPlayerInfo() { return PlayerInfo; }


protected:
	class Protocol::MoveInfo* PlayerInfo; // 현재 위치
	class Protocol::MoveInfo* DestInfo; // 목적지
};
