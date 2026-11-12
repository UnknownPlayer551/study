hello = os.getenv('HELLO')
world = os.getenv('WORLD')

if hello == nil or world == nil then
    print('No value assigned!')
    os.exit(1)
end
print(hello .. world)
