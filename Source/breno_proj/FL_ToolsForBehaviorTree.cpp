// Fill out your copyright notice in the Description page of Project Settings.


#include "FL_ToolsForBehaviorTree.h"
#include "Kismet/KismetMathLibrary.h"
#include "Camera/CameraComponent.h"
//Check if Pawn is in Observer sight based on FOV
bool UFL_ToolsForBehaviorTree::IsOnRadialRange(AActor* Pawn, UCameraComponent* Visualizer, float Fov, float MinFOV, float MaxFOV)
{
    FRotator Lookrot = UKismetMathLibrary::FindLookAtRotation(Pawn->GetActorLocation(), Visualizer->GetComponentLocation());
    FVector LrForward = UKismetMathLibrary::GetForwardVector(Lookrot);
    FVector VisualizerForward = Visualizer->GetForwardVector();
    float DotProdResult = FVector::DotProduct(LrForward, VisualizerForward);
	float NormFOV = UKismetMathLibrary::NormalizeToRange(Fov, MinFOV, MaxFOV);

	return  ((1-NormFOV) + DotProdResult) < 0;// Subtracting 1 by the NormalizedFOV to get cartesian angle difference between Visualizer and Observed
}