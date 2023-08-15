// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "RealtimeMeshActor.h"
#include "RealtimeMeshSimple.h"
#include "RealtimeMeshLibrary.h"
#include "MeshProvider.generated.h"

UCLASS()
class PROCEDURALGENERATION_API AMeshProvider : public ARealtimeMeshActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMeshProvider();
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	USceneComponent* RootComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	URealtimeMeshSimple* RTMesh;
	URealtimeMeshComponent* MeshComponent;
	// Function to create a simple triangle mesh
	void CreateTriangleMesh();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
