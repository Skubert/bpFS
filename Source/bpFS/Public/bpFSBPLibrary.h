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

	UFUNCTION(BlueprintPure, Category = "bpFS|DirectoryGetter")
	static FString GetPathToGame();

	UFUNCTION(BlueprintPure, Category = "bpFS|DirectoryGetter")
	static FString GetPathToEngine();

	UFUNCTION(BlueprintPure, Category = "bpFS|DirectoryGetter")
	static FString GetPathToGameContent();

	UFUNCTION(BlueprintPure, Category = "bpFS|DirectoryGetter")
	static FString GetPathToEngineContent();

	UFUNCTION(BlueprintPure, Category = "bpFS|DirectoryGetter")
	static FString GetPathToGamePlugins();

	UFUNCTION(BlueprintPure, Category = "bpFS|DirectoryGetter")
	static FString GetPathToEnginePlugins();

	UFUNCTION(BlueprintPure, Category = "bpFS|DirectoryGetter")
	static FString GetLaunchDir();

	/* Get all files from given directory. */
	UFUNCTION(BlueprintPure, Category = "bpFS|FileManagement")
	static bool GetAllFilesFromPath(TArray<FString>& files, FString directoryPath, bool showFolders, FString extension);

	UFUNCTION(BlueprintCallable, Category = "bpFS|FileManagement")
	static bool CreateDirectory(FString newDirPath);

	UFUNCTION(BlueprintCallable, Category = "bpFS|FileManagement")
	static bool DeleteFile(FString filePath);

	UFUNCTION(BlueprintCallable, Category = "bpFS|FileManagement")
	static EFileSystemResponse MoveFile(FString sourcePath, FString destinationPath);

	UFUNCTION(BlueprintCallable, Category = "bpFS|FileManagement")
	static EFileSystemResponse CopyFile(FString sourcePath, FString destinationPath);

	UFUNCTION(BlueprintCallable, Category = "bpFS|FileManagement")
	static bool DeleteDirectory(FString dirPath);

	UFUNCTION(BlueprintCallable, Category = "bpFS|FileManagement")
	static bool DeleteDirectoryRecursively(FString dirPath);

	UFUNCTION(BlueprintCallable, Category = "bpFS|FileManagement")
	static bool CopyDirectoryRecursively(FString sourcePath, FString destinationPath, bool Overwrite);

	UFUNCTION(BlueprintPure, Category = "bpFS")
	static bool DoesDirectoryExist(FString dirPath);

	UFUNCTION(BlueprintPure, Category = "bpFS")
	static bool DoesFileExist(FString filePath);

	/* Returns true if file exists, false if it does not exist */
	UFUNCTION(BlueprintPure, Category = "bpFS|FileProperties")
	static bool GetTimeStamp(FString filePath, FDateTime& timeModified);

	/* Returns true if file exists, false if it does not exist */
	UFUNCTION(BlueprintPure, Category = "bpFS|FileProperties")
	static bool IsReadOnly(FString filePath, bool& readOnly);

	/* Returns true if file exists, false if it does not exist */
	UFUNCTION(BlueprintPure, Category = "bpFS|FileProperties")
	static bool SetReadOnly(FString filePath, bool readOnly);

	/* Returns size of specified file in bytes. Returns -1 when file is not found, or given path points to directory. */
	UFUNCTION(BlueprintPure, Category = "bpFS|FileProperties")
	static int32 GetFileSize(FString filePath);

	/* Will create a new file if it does not exist */
	UFUNCTION(BlueprintCallable, Category = "bpFS")
	static bool SaveStringToFile(FString str, FString filePath);

	UFUNCTION(BlueprintCallable, Category = "bpFS")
	static bool LoadFileToString(FString str, FString& filePath);

};
