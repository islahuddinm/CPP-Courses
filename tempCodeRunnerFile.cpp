civilEngineer(civilEngineer& source)
    : engineer(source), contract(source.contract) // 'engineer(source)' call all its data for '(civilEngineer& source)'
    {
        std::cout << "Costum copy constructor Civil Engineer" << '\n';
    }