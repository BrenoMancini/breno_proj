// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Camera/CameraComponent.h"
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FL_ToolsForBehaviorTree.generated.h"

/**
 * 
 */
UCLASS()
class BRENO_PROJ_API UFL_ToolsForBehaviorTree : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	public:
    UFUNCTION(BlueprintCallable, Category = "Math")
		static bool IsOnRadialRange(AActor* Pawn, UCameraComponent* Visualizer, float Fov, float MinFOV, float MaxFOV);
	};
