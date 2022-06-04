#pragma once

#include "pch.h"
#include <string>
#include <iostream>
#include <filesystem>
#include <vector>
#include <thread>

namespace fs = std::filesystem;

namespace module {
	void SearchInsideFolders(const fs::path directory, const fs::path file_name, std::vector<std::string>* r, bool* isThreadTerminate) {
        for (const auto& entry : fs::directory_iterator(directory, fs::directory_options::skip_permission_denied)) {
            if (*isThreadTerminate) {

                return;
            }
            if (entry.is_directory()) {

                (*r).push_back(entry.path().string());
            }
            else if (entry.path().filename() == file_name) {

                std::cout << entry.path().string() << std::endl;
                *isThreadTerminate = 1;
                return;
            }
        }

        return;
	}

	void SearchManager(std::string file_name) {
        std::vector<std::string> r;     // vector to save the address to folders
        const int threadNum = 8;        // Max num of thread
        std::vector<std::vector<std::string>> rr(threadNum);   // vector for saving new sub-directory
        bool isThreadTerminate = 0;     // bool for thread/app terminate
        std::string path = "C:\\";

        module::SearchInsideFolders(path, file_name, &r, &isThreadTerminate);     // 0-instance call

        std::vector<std::thread> threads;   // vector to save info about threads
        int i = 0;
        while (i < r.size() && !isThreadTerminate) {
            // run up to 8 threads
            for (int j = 0; j < threadNum && i < r.size(); j++) {

                threads.emplace_back(module::SearchInsideFolders, r[i], file_name, &rr[j], &isThreadTerminate);
                i++;
            }

            // wait until all thread finish their job
            for (std::thread& t : threads) {

                t.join();
            }
            threads.clear();

            // add new sub folders addresses to the general vector of folder addresses
            for (int i = 0; i < threadNum; i++) {

                r.insert(r.end(), rr[i].begin(), rr[i].end());
                rr[i].clear();
            }
        }

        if (!isThreadTerminate) {
            std::cout << "File is not found." << std::endl;
        }
	}
}

