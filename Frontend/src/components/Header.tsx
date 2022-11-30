import React, { useState } from 'react';
import { Row, Layout, Menu, Typography, Button, Input, Col, Form, Avatar } from 'antd';
import type { MenuProps } from 'antd';
import { useNavigate } from 'react-router-dom';
import {
  HeatMapOutlined, MacCommandOutlined,
  MessageOutlined, CodeSandboxOutlined, ShareAltOutlined,
  SettingOutlined, QuestionCircleOutlined, SearchOutlined, UserOutlined
} from '@ant-design/icons';

const { Sider } = Layout;

function _Header(): any {
  const navigate: any = useNavigate();

  const [state, setState]: any = useState({ current: '' });

  const onClick: MenuProps['onClick'] = e => {
    setState({
      current: e.key,
    });

    navigate(`/${e.key}`);
  };

  return (
    <>
      <Sider
        collapsible
        trigger={null}
        width={100}
      >
        <Row
          align='middle'
          justify='space-between'
          className='logo'
        >
          <HeatMapOutlined />
        </Row>
        <Row align='middle' justify='space-between'>
          <Menu
            theme='dark'
            defaultSelectedKeys={['1']}
            mode='inline'
            className='row-icons'
          >
            <Menu.Item key='t'>
              <MacCommandOutlined />
            </Menu.Item>
            <Menu.Item key='t'>
              <MessageOutlined />
            </Menu.Item>
            <Menu.Item key='t'>
              <CodeSandboxOutlined />
            </Menu.Item>
            <Menu.Item key='t'>
              <ShareAltOutlined />
            </Menu.Item>
            <Menu.Item key='t'>
              <SettingOutlined />
            </Menu.Item>
            <Menu.Item key='t'>
              <QuestionCircleOutlined />
            </Menu.Item>
            <Menu.Item key='t'>
              <MacCommandOutlined />
            </Menu.Item>
          </Menu>
        </Row>
      </Sider>
    </>
  );
}

export default _Header;
