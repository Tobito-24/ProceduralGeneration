// Fill out your copyright notice in the Description page of Project Settings.


#include "MeshProvider.h"

// Sets default values
AMeshProvider::AMeshProvider()
{
    // Set this actor to call Tick() every frame
    PrimaryActorTick.bCanEverTick = true;
    RTMesh = CreateDefaultSubobject<URealtimeMeshSimple>(TEXT("RTMesh"));
    // Create the procedural mesh componentSim
    CreateTriangleMesh();
}

// Called when the game starts or when spawned
void AMeshProvider::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMeshProvider::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMeshProvider::CreateTriangleMesh()
{
    TArray<FVector> Vertices;
    Vertices.Add(FVector(0.f, 0.f, 0.f));          // Vertex 0
    Vertices.Add(FVector(100.f, 0.f, 0.f));        // Vertex 1
    Vertices.Add(FVector(50.f, 0.f, 100.f));        // Vertex 2

    TArray<int32> Triangles;
    Triangles.Add(0);
    Triangles.Add(1);
    Triangles.Add(2);

    TArray<FVector> Normals;
    Normals.Add(FVector(0.f, 0.f, 1.f));            // Normal for the entire triangle

    TArray<FVector2D> UV0;
    UV0.Add(FVector2D(0.f, 0.f));                   // UV coordinate for Vertex 0
    UV0.Add(FVector2D(1.f, 0.f));                   // UV coordinate for Vertex 1
    UV0.Add(FVector2D(0.5f, 1.f));                  // UV coordinate for Vertex 2

    TArray<FLinearColor> VertexColors;
    VertexColors.Add(FLinearColor::Red);            // Color for Vertex 0
    VertexColors.Add(FLinearColor::Green);          // Color for Vertex 1
    VertexColors.Add(FLinearColor::Blue);           // Color for Vertex 2
    TArray<FVector> Tangents;
    FRealtimeMeshSimpleMeshData MeshData;
    MeshData.Positions = Vertices;
    MeshData.Triangles = Triangles;
    MeshData.Normals = Normals;
    MeshData.LinearColors = VertexColors;




    FRealtimeMeshSectionKey StaticSectionKey = RTMesh->CreateMeshSection(0,
        FRealtimeMeshSectionConfig(ERealtimeMeshSectionDrawType::Static, 0), MeshData, true);
    RTMesh->UpdateSectionMesh(StaticSectionKey, MeshData);
}