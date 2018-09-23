#pragma once

#include "Engine.h"
#include "bpFSBPLibrary.generated.h"

UENUM(BlueprintType)
enum class EFileSystemResponse : uint8 {
	IO_Success		UMETA(DisplayName = "Success"),
	IO_SourceNull 	UMETA(DisplayName = "Source doesn't exist"),
	IO_DestExist	UMETA(DisplayName = "File already exists"),
	IO_Fail			UMETA(DisplayName = "Unknown Error")
};

UCLASS()
class UbpFSBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_UCLASS_BODY()

	UFUNCTION(BlueprintPure, Category = "bpIO")
	static FString GetPathToGame();

	UFUNCTION(BlueprintPure, Category = "bpIO")
	static FString GetPathToEngine();

	UFUNCTION(BlueprintPure, Category = "bpIO")
	static FString GetPathToGameContent();

	UFUNCTION(BlueprintPure, Category = "bpIO")
	static FString GetPathToEngineContent();

	UFUNCTION(BlueprintPure, Category = "bpIO")
	static FString GetPathToGamePlugins();

	UFUNCTION(BlueprintPure, Category = "bpIO")
	static FString GetPathToEnginePlugins();

	UFUNCTION(BlueprintPure, Category = "bpIO")
	static FString GetLaunchDir();

	/* Get all files from given directory. */
	UFUNCTION(BlueprintPure, Category = "bpIO")
	static bool GetAllFilesFromPath(TArray<FString>& files, FString directoryPath, bool showFolders, FString extension);

	/* Returns size of specified file in bytes. Returns -1 when file is not found, or given path points to directory. */
	UFUNCTION(BlueprintPure, Category = "bpIO")
	static int32 GetFileSize(FString filePath);

	UFUNCTION(BlueprintCallable, Category = "bpIO")
	static bool CreateDirectory(FString newDirPath);

	UFUNCTION(BlueprintCallable, Category = "bpIO")
	static bool DeleteFile(FString filePath);

	UFUNCTION(BlueprintCallable, Category = "bpIO")
	static EFileSystemResponse MoveFile(FString sourcePath, FString destinationPath);

	UFUNCTION(BlueprintCallable, Category = "bpIO")
	static EFileSystemResponse CopyFile(FString sourcePath, FString destinationPath);

	UFUNCTION(BlueprintCallable, Category = "bpIO")
	static bool DeleteDirectory(FString dirPath);

	UFUNCTION(BlueprintCallable, Category = "bpIO")
	static bool DeleteDirectoryRecursively(FString dirPath);

	UFUNCTION(BlueprintCallable, Category = "bpIO")
	static bool CopyDirectoryRecursively(FString sourcePath, FString destinationPath, bool Overwrite);

	UFUNCTION(BlueprintPure, Category = "bpIO")
	static bool DoesDirectoryExist(FString dirPath);

	UFUNCTION(BlueprintPure, Category = "bpIO")
	static bool DoesFileExist(FString filePath);

};
