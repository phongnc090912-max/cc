local key = {string.char(112,104,111,110,103,100,101,112,116,114,97,105,48,57,48,57,49,50,33)}

local Rayfield = loadstring(game:HttpGet('https://sirius.menu/rayfield'))()

local Window = Rayfield:CreateWindow({
   Name = "Vo1d scripts",
   Icon = 0,        
   LoadingTitle = "Exploit tool",
   LoadingSubtitle = "by Vo1d",
   ShowText = "Vo1d",
   Theme = "Amethyst",

   ToggleUIKeybind = "K",

   DisableRayfieldPrompts = false,
   DisableBuildWarnings = false,

   ConfigurationSaving = {
      Enabled = false,
      FolderName = nil,
      FileName = "Big Hub"
   },

   KeySystem = true,
   KeySettings = {
      Title = "Vo1d | Key",
      Subtitle = "Key System",
      Note = "Get the key on https://docs.google.com/document/d/16iatNXWzFK39oa7oYVQ7656TTHumxM2pPDUw7Wc3iVI/edit?hl=vi&tab=t.0",
      FileName = "Key",
      SaveKey = true,
      GrabKeyFromSite = false,
      Key = key
   }
})

local MainTab = Window:CreateTab("Movement", nil)
local FlyTab = Window:CreateTab("Fly", nil)

Rayfield:Notify({
   Title = "TOOL EXECUTED",
   Content = "The tool is running",
   Duration = 5,
   Image = nil,
   Action = {
      Ignore = {
         Name = "Okay!",
         Callback = function()
            print("The user tapped Okay!")
         end
      }
   }
})

local player = game.Players.LocalPlayer
local speed = 16

local function bindHumanoid(humanoid)
   humanoid.WalkSpeed = speed
   humanoid:GetPropertyChangedSignal("WalkSpeed"):Connect(function()
      if humanoid.WalkSpeed ~= speed then
         humanoid.WalkSpeed = speed
      end
   end)
end

local function onCharacterSpeed(char)
   local humanoid = char:WaitForChild("Humanoid")
   bindHumanoid(humanoid)
end

if player.Character then
   onCharacterSpeed(player.Character)
end
player.CharacterAdded:Connect(onCharacterSpeed)

local SpeedSlider = MainTab:CreateSlider({
   Name = "WALKSPEED",
   Range = {10, 360},
   Increment = 1,
   Suffix = "speed",
   CurrentValue = 16,
   Flag = "Slider1", 
   Callback = function(Value)
      speed = Value
      local char = player.Character
      if char then
         local hum = char:FindFirstChild("Humanoid")
         if hum then hum.WalkSpeed = speed end
      end
   end,
})

local UIS = game:GetService("UserInputService")
local RunService = game:GetService("RunService")

local jumpPower = 50

local function bindHumanoid(humanoid)
   humanoid.UseJumpPower = true
   humanoid.JumpPower = jumpPower
   humanoid:GetPropertyChangedSignal("JumpPower"):Connect(function()
      if humanoid.UseJumpPower and humanoid.JumpPower ~= jumpPower then
         humanoid.JumpPower = jumpPower
      end
   end)
end

local function onCharacterJumpPower(char)
   local humanoid = char:WaitForChild("Humanoid")
   bindHumanoid(humanoid)
end

if player.Character then
   onCharacterJumpPower(player.Character)
end
player.CharacterAdded:Connect(onCharacterJumpPower)

local JumpPowerSlider = MainTab:CreateSlider({
   Name = "Jump power",
   Range = {10, 360},
   Increment = 1,
   Suffix = "Power",
   CurrentValue = 50,
   Callback = function(Value)
      jumpPower = Value
      local char = player.Character
      if char then
         local hum = char:FindFirstChild("Humanoid")
         if hum then
            hum.UseJumpPower = true
            hum.JumpPower = jumpPower
         end
      end
   end
})

local infJump = false
local characterJumpinf
local humanoid

local function bindCharacterJumpinf(char)
   characterJumpinf = char
   humanoid = char:WaitForChild("Humanoid")
end

local function onCharacterJumpinf(char)
   bindCharacterJumpinf(char)
end

if player.Character then
    onCharacterJumpinf(player.Character)
end
player.CharacterAdded:Connect(onCharacterJumpinf)

local function setupInfJump()
   UIS.JumpRequest:Connect(function()
      if infJump and humanoid then
         humanoid:ChangeState(Enum.HumanoidStateType.Jumping)
      end
   end)
end

setupInfJump()

local INFJumpToggle = MainTab:CreateToggle({
   Name = "INF Jump",
   CurrentValue = false,
   Callback = function(v)
      infJump = v
   end
})
