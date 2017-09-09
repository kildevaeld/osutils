#define CATCH_CONFIG_RUNNER
#include "catch.hpp"

std::string HomeDir;

int main(int argc, char* const argv[])
{
    Catch::Session session;

    int returnCode = session.applyCommandLine(argc, argv, Catch::Session::OnUnusedOptions::Ignore);
    if (returnCode != 0)
        return returnCode;

    for (auto token : session.unusedTokens()) {
        //printf("Token: %s\n", token.data.c_str());
        HomeDir = token.data;
    }

    return session.run();
}