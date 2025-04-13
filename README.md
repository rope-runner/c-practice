# Build and run

- install bear, for macos: `brew install bear` for linux: `apt insall bear`
- build: `bear -- make build`, it will build into `./bin` and also will generate
    `compile_commands.json` that will be used by clangd lsp to properly link
    header files from `./include` into source files in `./src` and you will inlcude
    headers without relative pahts, just like `#inlcude "header.h"`
- run: `./bin/build`

