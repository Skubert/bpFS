#include "bpFSBPLibrary.h"
#include "bpFS.h"

UbpFSBPLibrary::UbpFSBPLibrary(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
{

}

FString UbpFSBPLibrary::GetPathToGame() {
	FString tempPath = FPaths::GameDir();
	FPaths::NormalizeDirectoryName(tempPath);
	return tempPath;
}

FString UbpFSBPLibrary::GetPathToEngine() {
	FString tempPath = FPaths::EngineDir();
	FPaths::NormalizeDirectoryName(tempPath);
	return tempPath;
}

FString UbpFSBPLibrary::GetPathToGameContent() {
	FString tempPath = FPaths::GameContentDir();
	FPaths::NormalizeDirectoryName(tempPath);
	return tempPath;
}

FString UbpFSBPLibrary::GetPathToEngineContent() {
	FString tempPath = FPaths::EngineContentDir();
	FPaths::NormalizeDirectoryName(tempPath);
	return tempPath;
}

FString UbpFSBPLibrary::GetPathToGamePlugins() {
	FString tempPath = FPaths::GamePluginsDir();
	FPaths::NormalizeDirectoryName(tempPath);
	return tempPath;
}

FString UbpFSBPLibrary::GetPathToEnginePlugins() {
	FString tempPath = FPaths::EnginePluginsDir();
	FPaths::NormalizeDirectoryName(tempPath);
	return tempPath;
}

FString UbpFSBPLibrary::GetLaunchDir() {
	FString tempPath = FPaths::LaunchDir();
	FPaths::NormalizeDirectoryName(tempPath);
	return tempPath;
}

bool UbpFSBPLibrary::GetAllFilesFromPath(TArray<FString>& files, FString directoryPath, bool showFolders, FString extension) {
	if (directoryPath.Len() < 1) return false;

	FPaths::NormalizeDirectoryName(directoryPath);

	IFileManager& FileManager = IFileManager::Get();

	if (extension == "")
	{
		extension = "*.*";
	}
	else
	{
		extension = (extension.Left(1) == ".") ? "*" + extension : "*." + extension;
	}

	FString FinalPath = directoryPath + "/" + extension;
	FileManager.FindFiles(files, *FinalPath, true, showFolders);

	return true;
}

int32 UbpFSBPLibrary::GetFileSize(FString filePath) {

	if (!FPlatformFileManager::Get().GetPlatformFile().FileExists(*filePath)) { return -1; }

	const int32 FileSize = FPlatformFileManager::Get().GetPlatformFile().FileSize(*filePath);

	return FileSize;
}

bool UbpFSBPLibrary::CreateDirectory(FString newDirPath)
{
	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();

	if (!PlatformFile.DirectoryExists(*newDirPath)) {

		PlatformFile.CreateDirectory(*newDirPath);

		if (!PlatformFile.DirectoryExists(*newDirPath)) {
			return false;
		}
	} return true;
}

bool UbpFSBPLibrary::DeleteFile(FString filePath) {

	if (!FPlatformFileManager::Get().GetPlatformFile().DeleteFile(*filePath)) {
		return false;
	}
	return true;
}

EFileSystemResponse UbpFSBPLibrary::MoveFile(FString sourcePath, FString destinationPath) {

	if (FPlatformFileManager::Get().GetPlatformFile().FileExists(*destinationPath)) {
		return EFileSystemResponse::IO_DestExist;
	}

	if (!FPlatformFileManager::Get().GetPlatformFile().FileExists(*sourcePath)) {
		return EFileSystemResponse::IO_SourceNull;
	}

	if (!FPlatformFileManager::Get().GetPlatformFile().MoveFile(*destinationPath, *sourcePath)) {
		return EFileSystemResponse::IO_Fail;
	}
	return EFileSystemResponse::IO_Success;
}

EFileSystemResponse UbpFSBPLibrary::CopyFile(FString sourcePath, FString destinationPath) {

	if (FPlatformFileManager::Get().GetPlatformFile().FileExists(*destinationPath)) {
		return EFileSystemResponse::IO_DestExist;
	}

	if (!FPlatformFileManager::Get().GetPlatformFile().FileExists(*sourcePath)) {
		return EFileSystemResponse::IO_SourceNull;
	}

	if (!FPlatformFileManager::Get().GetPlatformFile().CopyFile(*destinationPath, *sourcePath)) {
		return EFileSystemResponse::IO_Fail;
	}
	return EFileSystemResponse::IO_Success;
}

bool UbpFSBPLibrary::DeleteDirectory(FString dirPath) {

	if (!FPlatformFileManager::Get().GetPlatformFile().DeleteDirectory(*dirPath)) {
		return false;
	}
	return true;
}

bool UbpFSBPLibrary::DeleteDirectoryRecursively(FString dirPath) {

	if (!FPlatformFileManager::Get().GetPlatformFile().DeleteDirectoryRecursively(*dirPath)) {
		return false;
	}
	return true;
}

bool UbpFSBPLibrary::CopyDirectoryRecursively(FString sourcePath, FString destinationPath, bool Overwrite) {

	if (!FPlatformFileManager::Get().GetPlatformFile().CopyDirectoryTree(*destinationPath, *sourcePath, Overwrite)) {
		return false;
	}
	return true;
}

bool UbpFSBPLibrary::DoesDirectoryExist(FString dirPath) {

	if (!FPlatformFileManager::Get().GetPlatformFile().DirectoryExists(*dirPath)) {
		return false;
	}
	return true;
}

bool UbpFSBPLibrary::DoesFileExist(FString filePath) {

	if (!FPlatformFileManager::Get().GetPlatformFile().FileExists(*filePath)) {
		return false;
	}
	return true;
}

//------------------------------------

bool UbpFSBPLibrary::SaveStringToFile(FString str, FString filePath)
{
	return FFileHelper::SaveStringToFile(str, *filePath);
}

bool UbpFSBPLibrary::LoadFileToString(FString str, FString& filePath)
{
	return FFileHelper::LoadFileToString(str, *filePath);
}