#include "stdafx.h"
#include <windows.h>
#include <tchar.h>
#include <stdio.h>

void MonitorDirectory(const TCHAR *dirPath) {
    HANDLE hDir = CreateFile(
        dirPath,
        FILE_LIST_DIRECTORY,
        FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE,
        NULL,
        OPEN_EXISTING,
        FILE_FLAG_BACKUP_SEMANTICS,
        NULL
    );

    if (hDir == INVALID_HANDLE_VALUE) {
        _tprintf(_T("Error opening directory (%d)\n"), GetLastError());
        return;
    }

    BYTE buffer[4096];
    DWORD bytesReturned;

    while (ReadDirectoryChangesW(
        hDir,
        buffer,
        sizeof(buffer),
        FALSE,  // Watch the entire subtree
        FILE_NOTIFY_CHANGE_FILE_NAME | FILE_NOTIFY_CHANGE_DIR_NAME | FILE_NOTIFY_CHANGE_ATTRIBUTES |
            FILE_NOTIFY_CHANGE_SIZE | FILE_NOTIFY_CHANGE_LAST_WRITE | FILE_NOTIFY_CHANGE_SECURITY,
        &bytesReturned,
        NULL,
        NULL
    ))
    {
        FILE_NOTIFY_INFORMATION *info = (FILE_NOTIFY_INFORMATION *)buffer;
        do {
            // Process the change information
            if (info->Action == FILE_ACTION_REMOVED || info->Action == FILE_ACTION_REMOVED) {
                _tprintf(_T("File deleted: %.*s\n"), info->FileNameLength / sizeof(WCHAR), info->FileName);
            }

            info = (FILE_NOTIFY_INFORMATION *)((BYTE *)info + info->NextEntryOffset);
        } while (info->NextEntryOffset);
    }

    CloseHandle(hDir);
}

int _tmain(int argc, _TCHAR *argv[]) {
    if (argc != 2) {
        _tprintf(_T("Usage: %s <directory>\n"), argv[0]);
        return 1;
    }

    MonitorDirectory(argv[1]);

    return 0;
}
